#pragma once

#include <cstddef>
#include <filesystem>
#include <optional>
#include <vector>

#include <getopt.h>

struct Settings
{
	std::vector<std::filesystem::path> InputFiles;
	std::size_t                        Threads   = 2;
	bool                               Verbose   = true;
	bool                               Check     = false;
	bool                               Recursive = false;
};

extern const char* Usage;

const static struct option CommandOptions[] = {
	{"threads", required_argument, nullptr, 't'},
	{"check", no_argument, nullptr, 'c'},
	{"recursive", no_argument, nullptr, 'r'},
	{"help", no_argument, nullptr, 'h'},
	{nullptr, no_argument, nullptr, '\0'},
};

int CheckSFVs(const Settings& CurSettings);
int GenerateSFV(const Settings& CurSettings);