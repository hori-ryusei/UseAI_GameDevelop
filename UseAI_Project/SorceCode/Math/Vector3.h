#pragma once

#include <cmath>

class Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3(): x(0.0f), y(0.0f), z(0.0f){}

    Vector3(float value): x(value), y(value), z(value){}

    Vector3(float xValue, float yValue, float zValue): x(xValue), y(yValue), z(zValue){}

    static Vector3 Zero()
    {
        return Vector3(0.0f, 0.0f, 0.0f);
    }

    static Vector3 One()
    {
        return Vector3(1.0f, 1.0f, 1.0f);
    }

    static Vector3 Up()
    {
        return Vector3(0.0f, 1.0f, 0.0f);
    }

    static Vector3 Down()
    {
        return Vector3(0.0f, -1.0f, 0.0f);
    }

    static Vector3 Right()
    {
        return Vector3(1.0f, 0.0f, 0.0f);
    }

    static Vector3 Left()
    {
        return Vector3(-1.0f, 0.0f, 0.0f);
    }

    static Vector3 Forward()
    {
        return Vector3(0.0f, 0.0f, 1.0f);
    }

    static Vector3 Back()
    {
        return Vector3(0.0f, 0.0f, -1.0f);
    }

    //代入
    /// <summary>代入</summary>
    Vector3& operator=(const Vector3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    /// <summary>代入</summary>
    Vector3& operator=(float value)
    {
        x = value;
        y = value;
        z = value;
        return *this;
    }

    //演算
    //Vector3
    /// <summary>加法</summary>
    Vector3 operator+(const Vector3& other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    /// <summary>減法</summary>
    Vector3 operator-(const Vector3& other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    /// <summary>乗法</summary>
    Vector3 operator*(const Vector3& other) const
    {
        return Vector3(x * other.x, y * other.y, z * other.z);
    }

    /// <summary>除法</summary>
    Vector3 operator/(const Vector3& other) const
    {
        const float epsilon = 0.00001f;

        return Vector3(
            std::fabs(other.x) < epsilon ? x : x / other.x,
            std::fabs(other.y) < epsilon ? y : y / other.y,
            std::fabs(other.z) < epsilon ? z : z / other.z
        );
    }

    //float
    /// <summary>加法</summary>
    Vector3 operator+(float value) const
    {
        return Vector3(x + value, y + value, z + value);
    }

    /// <summary>減法</summary>
    Vector3 operator-(float value) const
    {
        return Vector3(x - value, y - value, z - value);
    }

    /// <summary>乗法</summary>
    Vector3 operator*(float value) const
    {
        return Vector3(x * value, y * value, z * value);
    }

    /// <summary>除法</summary>
    Vector3 operator/(float value) const
    {
        const float epsilon = 0.00001f;

        if (std::fabs(value) < epsilon)
        {
            return *this;
        }

        return Vector3(x / value, y / value, z / value);
    }

    /// <summary>長さを取得(2乗)</summary>
    float LengthSQ() const
    {
        return x * x + y * y + z * z;
    }

    /// <summary>長さを取得</summary>
    float Length() const
    {
        return std::sqrt(LengthSQ());
    }

    /// <summary>正規化</summary>
    float Nomalize()
    {
        const float epsilon = 0.00001f;
        float length = Length();

        if (length < epsilon)
        {
            return length;
        }

        x /= length;
        y /= length;
        z /= length;

        return length;
    }

    /// <summary>正規化後の数値を取得</summary>
    Vector3 GetNomalize() const
    {
        Vector3 result = *this;
        result.Nomalize();
        return result;
    }

    /// <summary>内積</summary>
    static float Dot(const Vector3& a, const Vector3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    /// <summary>外積</summary>
    static Vector3 Cross(const Vector3& a, const Vector3& b)
    {
        return Vector3
        (
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );
    }
};
