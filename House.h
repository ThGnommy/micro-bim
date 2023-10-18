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
  Component(Component &other) = delete;
  Component &operator=(Component &other) = delete;
  Component(Component &&other) noexcept = delete;
  Component &operator=(const Component &other) = delete;
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

  virtual std::vector<Component *> GetChildren() const = 0;

  virtual void SetPosition(Position new_pos) { m_pos = new_pos; }
  virtual void SetSize(Size new_size) { m_size = new_size; }

  void SetTotalCost(int cost_to_add) { m_total_cost += cost_to_add; }
  int GetTotalCost() { return m_total_cost; }

  void SetNumberOfFloor(int new_number) { this->m_number_of_floor = new_number; }
  int GetNumberOfFloor() const { return this->m_number_of_floor; }

  virtual bool IsComposite() const { return false; }

  unsigned int floor_w{50};
  unsigned int floor_h{20};

  int m_number_of_floor{};
  int m_total_cost{0};

  Position m_pos{0, 0};
  Size m_size{0, 0};
};

class HouseComposite : public Component
{
public:
  HouseComposite() = default;

  void Build(Screen &s, Position pos = {0, 0}) override;

  void Add(Component *component) override;
  void BuildComponents(Screen &s) override;
  bool IsComposite() const override { return true; }
  std::vector<Component *> children;
  std::vector<Component *> GetChildren() const override { return this->children; }

  int m_cost{300000};
  float delivery_time{1.5f};
};

class FloorComposite : public Component
{
public:
  FloorComposite(Component *parent) : Component(parent) {}

  void Build(Screen &s, Position pos) override;

  void Add(Component *component) override;

  void BuildComponents(Screen &s) override;

  bool IsComposite() const override { return true; }

  std::vector<Component *> GetChildren() const override
  {
    return this->children;
  }

  std::vector<Component *> children;

  int m_cost{6000};
  float delivery_time{10.0f};
};

class Door : public Component
{
public:
  Door(Component *parent, Position _pos) : Component(parent), added_position(_pos)
  {
    SetSize({5, 7});
  }

  void Build(Screen &s, Position pos) override;

  int m_cost{700};
  float delivery_time{1.5f};

  Position added_position{};

private:
  void BuildComponents(Screen &s) override{};
  void Add(Component *component) override{};
  std::vector<Component *> GetChildren() const override { return std::vector<Component *>(); }
};

class Window : public Component
{
public:
  Window(Component *parent, Position _pos) : Component(parent), added_position(_pos)
  {
    SetSize({5, 5});
  }

  void Build(Screen &s, Position _pos) override;

  int m_cost{500};
  float delivery_time{1.5f};

  Position added_position{};

private:
  void Add(Component *component) override{};
  void BuildComponents(Screen &s) override{};
  std::vector<Component *> GetChildren() const override { return std::vector<Component *>(); }
};