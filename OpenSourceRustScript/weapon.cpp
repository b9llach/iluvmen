#include "weapon.h"
#include "tables.h"

void weapon::humanized(float delay, double control_time, int x, int y)
{
    int num = (int)delay - (int)control_time;
    control_time += (double)num;
    int num2 = 0;
    int num3 = 0;
    double num4 = 0.0;
    for (int i = 1; i <= (int)round(control_time); i++)
    {
        int num5 = i * (int)round((double)x) / (int)round(control_time);
        int num6 = i * (int)round((double)y) / (int)round(control_time);
        double num7 = (double)i * control_time / control_time;
        move_mouse(num5 - num2, num6 - num3);
        query_sleep((int)floor(num7 - num4));
        num2 = num5;
        num3 = num6;
        num4 = num7;
    }
}

void weapon::blatant(float delay, double control_time, float x, float y)
{
    int x_ = 0, y_ = 0, t_ = 0;
    for (int i = 1; i <= (int)control_time; ++i)
    {
        int xI = i * x / control_time;
        int yI = i * y / control_time;
        int tI = i * control_time / control_time;
        int xX = xI - x_;
        int yY = yI - y_;
        move_mouse(xX, yY);
        query_sleep(tI - t_);
        x_ = xI; y_ = yI; t_ = tI;
    }
    query_sleep((delay - control_time));
}

void weapon::query_sleep(int ms)
{
    LONGLONG timerResolution;
    LONGLONG wantedTime;
    LONGLONG currentTime;
    QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
    timerResolution /= 1000;
    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
    wantedTime = currentTime / timerResolution + ms;
    currentTime = 0;
    while (currentTime < wantedTime)
    {
        QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
        currentTime /= timerResolution;
    }
}

void weapon::move_mouse(int x, int y)
{
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.mouseData = 0;
    input.mi.time = 0;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    SendInput(1, &input, sizeof(input));
}

void weapon::get_info()
{
    if (cweapon == "AK47") {
        ctable = tables::ak::pattern;
        ccontroltime = tables::ak::controltime;
        cdelay = tables::ak::delay;
    }
    if (cweapon == "LR300") {
        ctable = tables::lr::pattern;
        ccontroltime = tables::lr::controltime;
        cdelay = tables::lr::delay;
    }
    if (cweapon == "CUSTOM") {
        ctable = tables::custom::pattern;
        ccontroltime = tables::custom::controltime;
        cdelay = tables::custom::delay;
    }
    if (cweapon == "TOMMY") {
        ctable = tables::thompson::pattern;
        ccontroltime  = tables::thompson::controltime;
        cdelay = tables::thompson::delay;
    }
    if (cweapon == "MP5") {
        ctable = tables::mp5::pattern;
        ccontroltime = tables::mp5::controltime;
        cdelay = tables::mp5::delay;
    }
}

float weapon::get_scope()
{
    if (cscope == "NONE") {
        return 1;
    }
    if (cscope == "HANDMADE") {
        if (cweapon == "TOMMY" || cweapon == "CUSTOM") {
            return .9;
        }
        return .8;
    }
    if (cscope == "HOLO") {
        if (cweapon == "TOMMY" || cweapon == "CUSTOM") {
            return 1.48605;
        }
        return 1.18605;
    }
    if (cscope == "8X") {
        if (cweapon == "TOMMY" || cweapon == "CUSTOM") {
            return 4.58721;
        }
        return 3.83721;
    }
    if (cscope == "16X") {
        if (cweapon == "TOMMY" || cweapon == "CUSTOM") {
            return 9.25116;
        }
        return  7.65116;
    }
    return 1;
}

float weapon::randomize(float value, int perc)
{
	return 0.0f;
}
