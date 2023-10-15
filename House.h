#pragma once

#include <iostream>
#include <vector>
#include "screenlib.h"

class Component
{
protected:
  Component *parent_;

public:
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
  // virtual void GetCost() const = 0;

  Position m_pos{};
  Size m_size{};
};

class HouseComposite : public Component
{
public:
  HouseComposite() = default;

  void Build(Screen &s) override
  {
    Box _house;

    s.UpdateScreen(s.m_width, 20);
    m_size = {s.m_width, 20};
    _house.Draw(s, m_size, m_pos, 'o');
  }

  void GetCost() const override;

  void Add(Component *component) override
  {
    this->children.push_back(component);
    component->SetParent(this);
  }

  void BuildComponents(Screen &s) override
  {
    for (Component *c : children)
    {
      c->Build(s);
    }
  }

  std::vector<Component *> children;

  Size m_size{};
  Position m_pos{0, 0};

  int cost{100};
  float delivery_time{1.5f};
};

class Floor : public Component
{
public:
  Floor() = default;

  void Build(Screen &s) override
  {
    auto house = GetParent();
    m_size = {house->m_size.w, 20};

    Box _floor;
    _floor.Draw(s, m_size, m_pos);
  };

  void GetCost() const;

  std::vector<Component *> children;

  void Add(Component *component) override
  {
    this->children.push_back(component);
    component->SetParent(this);
  }

  void BuildComponents(Screen &s) override{};

  Size m_size{};
  Position m_pos{0, 0};
  int cost{100};
  float delivery_time{1.5f};
};

class Window : public Component
{
  void Add(Component *component) override{};
  void Build(Screen &s) override
  {
  }

  virtual void GetCost() const;

  Size m_size{20, 20};
  Position m_pos{0, 0};
  int cost{100};
  float delivery_time{1.5f};
};

class Door : public Component
{
  void Add(Component *component) override{};
  void Build(Screen &s) override{};
  virtual void GetCost() const;

  Size m_size{20, 20};
  Position m_pos{0, 0};
  int cost{100};
  float delivery_time{1.5f};
};
