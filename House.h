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

  Component(Component &other) = delete; // copy constructor

  Component &operator=(Component &other) = delete; // copy assignment

  Component(Component &&other) noexcept = delete; // move constructor

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

  virtual void Build(Screen &s){};
  virtual void Add(Component *component) {}
  virtual void BuildComponents(Screen &s){};
  virtual int GetCost() const = 0;

  Position m_pos{0, 0};
  Size m_size{};
};

class HouseComposite : public Component
{
public:
  HouseComposite() = default;

  void Build(Screen &s) override;

  int GetCost() const override;

  void Add(Component *component) override;

  void BuildComponents(Screen &s) override;

  std::vector<Component *> children;

  int cost{100};
  float delivery_time{1.5f};
};

class FloorComposite : public Component
{
public:
  FloorComposite(Component *parent) : Component(parent)
  {
    Component *house = GetParent();
    m_size.w = house->m_size.w;
  }

  void Build(Screen &s) override;

  int GetCost() const override{};

  void Add(Component *component) override
  {
    this->children.push_back(component);
    component->SetParent(this);
  }

  void BuildComponents(Screen &s) override{};

  std::vector<Component *> children;

  // Size m_size{};
  // Position m_pos{};
  int cost{100};
  float delivery_time{1.5f};
};

// class Window : public Component
// {
// public:
//   void Build(Screen &s, Position _pos) override
//   {
//     Drawable _window;
//     _window.DrawBox(s, m_size, _pos);
//   }

//   int GetCost() const override{};

//   Size m_size{6, 6};
//   Position m_pos{0, 0};
//   int cost{100};
//   float delivery_time{1.5f};

// private:
//   void Add(Component *component) override{};
// };

// class Door : public Component
// {

// public:
//   void Build(Screen &s, Position _pos) override
//   {
//     Drawable _door;
//     _door.DrawBox(s, m_size, _pos);
//   };

//   void BuildComponents(Screen &s) override{};

//   int GetCost() const override{};

//   Size m_size{20, 20};
//   Position m_pos{0, 0};
//   int cost{100};
//   float delivery_time{1.5f};

// private:
//   void Add(Component *component) override{};
// };
