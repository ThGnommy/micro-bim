#pragma once

#include <iostream>
#include <vector>
#include "screenlib.h"

class Component
{
protected:
  Component *parent_ = nullptr;

public:
  Component(Component *parent = nullptr) : parent_(parent){};
  Component(Component &other) = delete;                  // copy constructor
  Component &operator=(Component &other) = delete;       // copy assignment
  Component(Component &&other) noexcept = delete;        // move constructor
  Component &operator=(const Component &other) = delete; // copy assignment
  virtual ~Component() {}

  void SetParent(Component *parent)
  {
    this->parent_ = parent;
  }

  Component *GetParent() const
  {
    return this->parent_;
  }

  virtual void Build(Screen &s, Position pos = {0, 0}){};
  virtual void Add(Component *component) {}
  virtual void BuildComponents(Screen &s){};
  virtual int GetCost() const = 0;
  virtual std::vector<Component *> GetChildren() const = 0;

  virtual void SetPosition(Position new_pos)
  {
    m_pos = new_pos;
  }

  virtual void SetSize(Size new_size)
  {
    m_size = new_size;
  }

  virtual bool IsComposite() const { return false; }
  void SetNumberOfFloor(int new_number) { this->number_of_floor = new_number; }
  int GetNumberOfFloor() const { return this->number_of_floor; }

  unsigned int floor_w{50};
  unsigned int floor_h{20};

  int number_of_floor{};

  Position m_pos{0, 0};
  Size m_size{0, 0};
};

class HouseComposite : public Component
{
public:
  HouseComposite() = default;

  void Build(Screen &s, Position pos = {0, 0}) override;

  int GetCost() const override;

  void Add(Component *component) override;
  void BuildComponents(Screen &s) override;
  std::vector<Component *> children;
  std::vector<Component *> GetChildren() const override { return this->children; }

  bool IsComposite() const override { return true; }

  int cost{100};
  float delivery_time{1.5f};
};

class FloorComposite : public Component
{
public:
  FloorComposite(Component *parent) : Component(parent) {}

  void Build(Screen &s, Position pos) override;

  int GetCost() const override { return cost; };

  void Add(Component *component) override
  {
    this->children.push_back(component);
    component->SetParent(this);
  }

  void BuildComponents(Screen &s) override;

  bool IsComposite() const override { return true; }

  std::vector<Component *> GetChildren() const override
  {
    return this->children;
  }

  std::vector<Component *> children;

  int cost{1000};
  float delivery_time{10.0f};
};

class Door : public Component
{
public:
  Door(Component *parent, Position _pos) : Component(parent), added_position(_pos)
  {
    SetSize({4, 6});
  }

  void Build(Screen &s, Position pos) override;
  int GetCost() const override { return cost; };

  std::vector<Component *> GetChildren() const override{};

  int cost{100};
  float delivery_time{1.5f};

  Position added_position{};

private:
  void BuildComponents(Screen &s) override{};
  void Add(Component *component) override{};
};

class Window : public Component
{
public:
  Window(Component *parent, Position _pos) : Component(parent), added_position(_pos)
  {
    SetSize({5, 5});
  }

  void Build(Screen &s, Position _pos) override;

  int GetCost() const override { return cost; };

  std::vector<Component *> GetChildren() const override{};

  int cost{60};
  float delivery_time{1.5f};

  Position added_position{};

private:
  void Add(Component *component) override{};
  void BuildComponents(Screen &s) override{};
};