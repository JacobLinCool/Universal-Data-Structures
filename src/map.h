/**
 * @file map.h
 * @author JacobLinCool <me@jacoblin.cool> (github.com/JacobLinCool)
 * @brief Map, key-value pairs
 * @copyright Copyright (c) 2022 JacobLinCool (MIT License)
 * @see https://github.com/JacobLinCool/Universal-Data-Structures
 */

#ifndef __UDS_MAP_H
#define __UDS_MAP_H

#include <stdint.h>

enum NodeColor { BLACK, RED };

#define StructRBNode(_name, _type)                                                                 \
    typedef struct RBNode {                                                                        \
        struct RBNode* left;                                                                       \
        struct RBNode* right;                                                                      \
        struct RBNode* parent;                                                                     \
        enum NodeColor color;                                                                      \
        int64_t        key;                                                                        \
        _type          data;                                                                       \
    } RBNode;                                                                                      \
    typedef struct _name {                                                                         \
        RBNode* root;                                                                              \
        RBNode* nil;                                                                               \
        size_t  size;                                                                              \
        size_t  capacity;                                                                          \
    };

#endif /* __UDS_MAP_H */