#ifndef __MATH_H__
#define __MATH_H__

// Here we use macros for performance because
// ncc doesn't yet support inline functions
#define sinf(__f) (asm (__f) -> float { sin_f32; })
#define cosf(__f) (asm (__f) -> float { cos_f32; })
#define atanf(__f) (asm (__f) -> float { atans_f32; })
#define sqrtf(__f) (asm (__f) -> float { sqrt_f32; })

#endif
