#pragma once
#include <string>
#include <vector>

void WriteSeparator(int count, char separator = '-');
void OutputBlock(std::string message, std::string character = "");
int AskChoice(const std::string& question, const std::vector<std::string>& options);
void Episode1();