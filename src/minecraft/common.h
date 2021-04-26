//
// Copyright (c) 2021 - jackk <jack@darkrp.sucks>, All rights reserved.
//

#ifndef MINECRAFT_SRC_MINECRAFT_COMMON_H_
#define MINECRAFT_SRC_MINECRAFT_COMMON_H_

#include <spdlog/spdlog.h>

#define MC_ASSERT_N(condition, message) \
if (!(condition)) { \
    spdlog::error("Assertion Failed: {}", message); \
    exit(1); \
} \

#endif //MINECRAFT_SRC_MINECRAFT_COMMON_H_
