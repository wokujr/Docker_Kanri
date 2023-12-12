#pragma once

#include <cstdint>
#include <string_view>
#include <iostream>
#include <fmt/format.h>
#include <imgui.h>
#include <implot.h>
#include "GLFW/glfw3.h"
#include <Windows.h>
#include <Psapi.h>

#include "font_awesome.h"
#include "font_awesome.cpp"
#include "font.hpp"
#include <filesystem>
#include <string_view>
#include <Windows.h>

namespace fs = std::filesystem;

class WindowClass
{

public:
    WindowClass() :
        iconsFont(nullptr),
        m_CurrentPath(fs::current_path()),
        m_SelectedPath(fs::path{})
    {

    }
public:
    void Draw(std::string_view label);
    static void render(WindowClass &window_obj);
    bool Initialize();
    float GetCPUUsage();
    size_t GetMemoryUsage();



private:
    ImFont* iconsFont;
    fs::path m_CurrentPath;
    fs::path m_SelectedPath;
    ImVec4 m_WindowBackground = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

protected:
    void DrawMenu();
    void DrawContent();
    void DrawColorPicker(std::string_view label);
};


