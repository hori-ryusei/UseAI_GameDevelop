#pragma once

#include <cmath>

class Quaternion
{
public:
    float x;
    float y;
    float z;
    float w;

    Quaternion(): x(0.0f), y(0.0f), z(0.0f), w(1.0f){}

    Quaternion(float value): x(value), y(value), z(value), w(value){}

    Quaternion(float xValue, float yValue, float zValue, float wValue): x(xValue), y(yValue), z(zValue), w(wValue){}

    static Quaternion Identity()
    {
        return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
    }

    //代入
    /// <summary>代入</summary>
    Quaternion& operator=(const Quaternion& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
        return *this;
    }

    /// <summary>乗法</summary>
    Quaternion& operator=(float value)
    {
        x = value;
        y = value;
        z = value;
        w = value;
        return *this;
    }

    /// <summary>加法</summary>
    Quaternion operator+(const Quaternion& other) const
    {
        return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    /// <summary>減法</summary>
    Quaternion operator-(const Quaternion& other) const
    {
        return Quaternion(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    /// <summary>乗法</summary>
    Quaternion operator*(const Quaternion& other) const
    {
        return Quaternion(
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w,
            w * other.w - x * other.x - y * other.y - z * other.z
        );
    }

    /// <summary>乗法</summary>
    Quaternion operator*(float value) const
    {
        return Quaternion(x * value, y * value, z * value, w * value);
    }

    /// <summary>除法</summary>
    Quaternion operator/(float value) const
    {
        const float epsilon = 0.00001f;

        if (std::fabs(value) < epsilon)
        {
            return *this;
        }

        return Quaternion(x / value, y / value, z / value, w / value);
    }

    //比較演算子
    bool operator==(const Quaternion& other) const
    {
        const float epsilon = 0.00001f;

        return std::fabs(x - other.x) < epsilon
            && std::fabs(y - other.y) < epsilon
            && std::fabs(z - other.z) < epsilon
            && std::fabs(w - other.w) < epsilon;
    }

    bool operator!=(const Quaternion& other) const
    {
        return !(*this == other);
    }

    /// <summary>長さを取得(2乗)</summary>
    float LengthSQ() const
    {
        return x * x + y * y + z * z + w * w;
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
        w /= length;

        return length;
    }

    /// <summary>正規化後の値を取得</summary>
    Quaternion GetNomalize() const
    {
        Quaternion result = *this;
        result.Nomalize();
        return result;
    }

    /// <summary>反対にする</summary>
    Quaternion Conjugate() const
    {
        return Quaternion(-x, -y, -z, w);
    }

    Quaternion Inverse() const
    {
        const float epsilon = 0.00001f;
        float lengthSQ = LengthSQ();

        if (lengthSQ < epsilon)
        {
            return *this;
        }

        return Conjugate() / lengthSQ;
    }
};
