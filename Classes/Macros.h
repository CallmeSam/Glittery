#ifndef __MACROS_H__
#define __MACROS_H__

#define NS_GTY_BEGIN  namespace Glittery {
#define NS_GTY_END	   }
#define USING_NS_GTY using namespace Glittery;
#define GTY_SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#endif // !__MACROS_H__
