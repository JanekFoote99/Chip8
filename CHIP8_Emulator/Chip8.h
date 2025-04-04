#pragma once
#include <cstdint>
#include <random>
#include <chrono>

class Chip8
{
public:
  uint8_t registers[16];
  uint8_t memory[4096];
  uint16_t index{};
  uint16_t pc{};
  uint16_t stack[16]{};
  uint8_t sp{};
  uint8_t delayTimer{};
  uint8_t soundTimer{};
  uint8_t keypad[16];
  uint32_t video[64 * 32];
  uint16_t opcode;
  std::default_random_engine randGen;
  std::uniform_int_distribution<uint8_t> randByte;

  void LoadROM(char const* filename);

  void OP_00E0();
  void OP_00EE();
  void OP_1nnn();
  void OP_2nnn();
};

