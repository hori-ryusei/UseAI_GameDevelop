#pragma once

#include <cmath>

class Vector2
{
public:
    float x;
    float y;

    Vector2(): x(0.0f), y(0.0f){}

    Vector2(float value): x(value), y(value){}

    Vector2(float xValue, float yValue): x(xValue), y(yValue){}

    static Vector2 Zero()
    {
        return Vector2(0.0f, 0.0f);
    }

    static Vector2 One()
    {
        return Vector2(1.0f, 1.0f);
    }

    static Vector2 Up()
    {
        return Vector2(0.0f, 1.0f);
    }

    static Vector2 Down()
    {
        return Vector2(0.0f, -1.0f);
    }

    static Vector2 Right()
    {
        return Vector2(1.0f, 0.0f);
    }

    static Vector2 Left()
    {
        return Vector2(-1.0f, 0.0f);
    }

    //代入
    /// <summary>代入</summary>
    Vector2& operator=(const Vector2& other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    /// <summary>代入</summary>
    Vector2& operator=(float value)
    {
        x = value;
        y = value;
        return *this;
    }

    //演算
    //Vector2
    /// <summary>加法</summary>
    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    /// <summary>減法</summary>
    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    /// <summary>乗法</summary>
    Vector2 operator*(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    /// <summary>除法</summary>
    Vector2 operator/(const Vector2& other) const
    {
        const float epsilon = 0.00001f;

        return Vector2(
            std::fabs(other.x) < epsilon ? x : x / other.x,
            std::fabs(other.y) < epsilon ? y : y / other.y
        );
    }

    //float
    /// <summary>加法</summary>
    Vector2 operator+(float value) const
    {
        return Vector2(x + value, y + value);
    }
    
    /// <summary>減法</summary>
    Vector2 operator-(float value) const
    {
        return Vector2(x - value, y - value);
    }

    /// <summary>乗法</summary>
    Vector2 operator*(float value) const
    {
        return Vector2(x * value, y * value);
    }

    /// <summary>除法</summary>
    Vector2 operator/(float value) const
    {
        const float epsilon = 0.00001f;

        if (std::fabs(value) < epsilon)
        {
            return *this;
        }

        return Vector2(x / value, y / value);
    }

    //比較演算
    bool operator==(const Vector2& other) const
    {
        const float epsilon = 0.00001f;

        return std::fabs(x - other.x) < epsilon
            && std::fabs(y - other.y) < epsilon;
    }

    bool operator!=(const Vector2& other) const
    {
        return !(*this == other);
    }

    /// <summary>長さを取得(2乗)</summary>
    float LengthSQ() const
    {
        return x * x + y * y;
    }

    /// <summary>長さを取得</summary>
    float Length() const
    {
        return std::sqrt(LengthSQ());
    }

    /// <summary>正規化</summary>
    void Nomalize()
    {
        const float epsilon = 0.00001f;
        float length = Length();

        if (length < epsilon)
        {
            return;
        }

        x /= length;
        y /= length;
    }

    /// <summary>正規化数値をセット</summary>
    Vector2 GetNomalize() const
    {
        Vector2 result = *this;
        result.Nomalize();
        return result;
    }

    /// <summary>内積</summary>
    static float Dot(const Vector2& a, const Vector2& b)
    {
        return a.x * b.x + a.y * b.y;
    }
};