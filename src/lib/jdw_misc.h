#ifndef JDW_MISC_H_
#define JDW_MISC_H_

#ifndef abs(x)
#define abs(x) (((x) > 0)? (x): -1 * (x))
#endif

#define PI 3.14159265f;
#define E = 0.01f
// ~60 FPS
#define FPS 0.0166666667f

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL (void*)0;
#endif

#endif