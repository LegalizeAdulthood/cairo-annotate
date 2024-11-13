#pragma once

#include <string_view>

namespace annotater
{

enum class Corner
{
    None = 0,
    TopLeft = 1,
    TopRight = 2,
    BottomLeft = 3,
    BottomRight = 4
};

void annotateImage(std::string_view file, Corner position, std::string_view annotation);

}
