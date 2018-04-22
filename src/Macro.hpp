#ifndef MACRO_HPP_
#define MACRO_HPP_

#define DELETE(ptr) if (ptr != nullptr) { delete ptr; }

#define STR(i) STR_(i)
#define STR_(i) #i

#endif
