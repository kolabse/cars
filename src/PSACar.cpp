#include <Arduino.h>
#include "PSACar.h"

void PSACar::setCanFilters(MCP2515 &mcp2515) {

    // Сбрасываем настройки платы MCP2515
    mcp2515.reset();

    // Устанавливаем скорость шины с которой будем работать и частоту кварца распаянного на плате
    mcp2515.setBitrate(CAN_125KBPS, MCP_16MHZ);

    // Переходим в режим конфигурации аппаратной части
    mcp2515.setConfigMode();
    // Добавляем маски фильтрации сообщений
    mcp2515.setFilterMask(MCP2515::MASK0, false, 0x7FF);
    mcp2515.setFilterMask(MCP2515::MASK1, false, 0x7FF);

    // Добавляем фильтры по id сообщений

    // Зажигание, яркость подсветки, режим энергосбережения http://autowp.github.io/#036
    mcp2515.setFilter(MCP2515::RXF0, false, 0x036);

    // Скорость вращения колес, напряжение аккумулятора http://autowp.github.io/#0E6
    mcp2515.setFilter(MCP2515::RXF1, false, 0x0E6);

    // Зажигание, Температура ОЖ, Одометр, Температура ОС, Задний ход, Правый поворотник, Левый поворотник http://autowp.github.io/#0F6
    mcp2515.setFilter(MCP2515::RXF2, false, 0x0F6);

    // Информация климатческой установки http://autowp.github.io/#1D0
    mcp2515.setFilter(MCP2515::RXF3, false, 0x1D0);

    mcp2515.setFilter(MCP2515::RXF4, false, 0x221);

    mcp2515.setFilter(MCP2515::RXF5, false, 0x276);

    // Переходим в режим нормальной работы
    mcp2515.setNormalMode();
}
