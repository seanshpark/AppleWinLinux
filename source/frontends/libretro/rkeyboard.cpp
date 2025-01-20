#include <cstdint>
#include <frontends/libretro/rkeyboard.h>

#include <unordered_map>
#include <array>

namespace
{
    const std::unordered_map<size_t, std::array<uint8_t, 3>> CODES = {
        {0x7f, {0x7f, 0x7f, 0x7f}}, {0x08, {0x08, 0x08, 0x08}}, {0x09, {0x09, 0x09, 0x09}}, {0x0a, {0x0a, 0x0a, 0x0a}},
        {0x0b, {0x0b, 0x0b, 0x0b}}, {0x0d, {0x0d, 0x0d, 0x0d}}, {0x15, {0x15, 0x15, 0x15}}, {0x1b, {0x1b, 0x1b, 0x1b}},
        {0x20, {0x20, 0x20, 0x20}},

        {0x27, {0x27, 0x22, 0x22}}, {0x2c, {0x2c, 0x3c, 0x3c}}, {0x2d, {0x1f, 0x5f, 0x1f}}, {0x2e, {0x2e, 0x3e, 0x3e}},
        {0x2f, {0x2f, 0x3f, 0x3f}}, {0x30, {0x30, 0x29, 0x29}}, {0x31, {0x31, 0x21, 0x21}}, {0x32, {0x00, 0x40, 0x00}},
        {0x33, {0x33, 0x23, 0x23}}, {0x34, {0x34, 0x24, 0x24}}, {0x35, {0x35, 0x25, 0x25}}, {0x36, {0x1e, 0x5e, 0x1e}},
        {0x37, {0x37, 0x26, 0x26}}, {0x38, {0x38, 0x2a, 0x2a}}, {0x39, {0x39, 0x28, 0x28}}, {0x3b, {0x3b, 0x3a, 0x3a}},
        {0x3d, {0x3d, 0x2b, 0x2b}},

        {0x5b, {0x1b, 0x7b, 0x1b}}, {0x5c, {0x1c, 0x7c, 0x1c}}, {0x5d, {0x1d, 0x7d, 0x1d}}, {0x60, {0x60, 0x7e, 0x7e}},
    };
}

namespace ra2
{
    bool getApple2Character(size_t keycode, bool ctrl, bool shift, uint8_t &out)
    {
        const auto it = CODES.find(keycode);
        if (it == CODES.end())
        {
            return false;
        }
        else
        {
            size_t pos = 0;
            if (ctrl)
                pos += 1;
            if (shift)
                pos += 2;
            if (pos == 0)
            {
                out = it->first;
            }
            else
            {
                out = it->second[pos - 1];
            }
            return true;
        }
    }

} // namespace ra2
