#pragma once

namespace imageutils
{
struct color
{
  float red;
  float green;
  float blue;
  float alpha;

  color() = default;
  ~color() = default;

  constexpr color(float c) : red(c), green(c), blue(c), alpha(1)
  {
  }

  constexpr color(float r, float g, float b) : red(r), green(g), blue(b), alpha(1)
  {
  }

  constexpr color(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a)
  {
  }

  constexpr color(const color& other) = default;
  constexpr color&
  operator=(const color& other) = default;

  constexpr color(color&& other) = default;
  constexpr color&
  operator=(color&& other) = default;

  friend constexpr bool
  operator==(const color& lhs, const color& rhs)
  {
    return lhs.red == rhs.red && lhs.green == rhs.green && lhs.blue == rhs.blue && lhs.alpha == rhs.alpha;
  }

  friend constexpr bool
  operator!=(const color& lhs, const color& rhs)
  {
    return !(lhs == rhs);
  }

  friend constexpr color&
  operator+=(color& lhs, const color& rhs)
  {
    lhs.red += rhs.red;
    lhs.green += rhs.green;
    lhs.blue += rhs.blue;
    lhs.alpha += rhs.alpha;
    return lhs;
  }

  friend constexpr color
  operator+(color lhs, const color& rhs)
  {
    return lhs += rhs;
  }

  friend constexpr color&
  operator-=(color& lhs, const color& rhs)
  {
    lhs.red -= rhs.red;
    lhs.green -= rhs.green;
    lhs.blue -= rhs.blue;
    lhs.alpha -= rhs.alpha;
    return lhs;
  }

  friend constexpr color
  operator-(color lhs, const color& rhs)
  {
    return lhs -= rhs;
  }

  friend constexpr color&
  operator*=(color& lhs, const color& rhs)
  {
    lhs.red *= rhs.red;
    lhs.green *= rhs.green;
    lhs.blue *= rhs.blue;
    lhs.alpha *= rhs.alpha;
    return lhs;
  }

  friend constexpr color
  operator*(color lhs, const color& rhs)
  {
    return lhs *= rhs;
  }

  friend constexpr color&
  operator/=(color& lhs, const color& rhs)
  {
    lhs.red /= rhs.red;
    lhs.green /= rhs.green;
    lhs.blue /= rhs.blue;
    lhs.alpha /= rhs.alpha;
    return lhs;
  }

  friend constexpr color
  operator/(color lhs, const color& rhs)
  {
    return lhs /= rhs;
  }

  friend constexpr color&
  operator+=(color& lhs, const float rhs)
  {
    lhs.red += rhs;
    lhs.green += rhs;
    lhs.blue += rhs;
    lhs.alpha += rhs;
    return lhs;
  }

  friend constexpr color
  operator+(color lhs, const float rhs)
  {
    return lhs += rhs;
  }

  friend constexpr color&
  operator-=(color& lhs, const float rhs)
  {
    lhs.red -= rhs;
    lhs.green -= rhs;
    lhs.blue -= rhs;
    lhs.alpha -= rhs;
    return lhs;
  }

  friend constexpr color
  operator-(color lhs, const float rhs)
  {
    return lhs -= rhs;
  }

  friend constexpr color&
  operator*=(color& lhs, const float rhs)
  {
    lhs.red *= rhs;
    lhs.green *= rhs;
    lhs.blue *= rhs;
    lhs.alpha *= rhs;
    return lhs;
  }

  friend constexpr color
  operator*(color lhs, const float rhs)
  {
    return lhs *= rhs;
  }

  friend constexpr color&
  operator/=(color& lhs, const float rhs)
  {
    lhs.red /= rhs;
    lhs.green /= rhs;
    lhs.blue /= rhs;
    lhs.alpha /= rhs;
    return lhs;
  }

  friend constexpr color
  operator/(color lhs, const float rhs)
  {
    return lhs /= rhs;
  }

  friend constexpr float&
  operator+=(float& lhs, const color& rhs)
  {
    return lhs += (rhs.red + rhs.green + rhs.blue) / 3.0f;
  }

  friend constexpr float
  operator+(float lhs, const color& rhs)
  {
    return lhs += rhs;
  }

  friend constexpr float&
  operator-=(float& lhs, const color& rhs)
  {
    return lhs -= (rhs.red + rhs.green + rhs.blue) / 3.0f;
  }

  friend constexpr float
  operator-(float lhs, const color& rhs)
  {
    return lhs -= rhs;
  }

  friend constexpr float&
  operator*=(float& lhs, const color& rhs)
  {
    return lhs *= (rhs.red + rhs.green + rhs.blue) / 3.0f;
  }

  friend constexpr float
  operator*(float lhs, const color& rhs)
  {
    return lhs *= rhs;
  }

  friend constexpr float&
  operator/=(float& lhs, const color& rhs)
  {
    return lhs /= (rhs.red + rhs.green + rhs.blue) / 3.0f;
  }

  friend constexpr float
  operator/(float lhs, const color& rhs)
  {
    return lhs /= rhs;
  }

};
}  // namespace imageutils
