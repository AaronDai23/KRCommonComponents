//
//  Macros.h
//
//  宏定义文件
//
//
//

#pragma mark - 各类key
#ifdef DEBUG
#define UM_KEY  @"5e5234e9570df33b8f00016a"
#else
#define UM_KEY  @"5e5234e9570df33b8f00016a"
#endif

#pragma mark - 宽高度宏定义
#define MSWIDTH [UIScreen mainScreen].bounds.size.width
#define MSHIGHT [UIScreen mainScreen].bounds.size.hight
#define ScreenWidth                         [[UIScreen mainScreen] bounds].size.width
#define ScreenHeight                        [[UIScreen mainScreen] bounds].size.height

#pragma mark - DEBUG
#ifdef DEBUG
#define                                         DLOG(...) NSLog(__VA_ARGS__)
#define                                         DLOG_METHOD NSLog(@"%s", __func__)
#define                                         DLOGERROR(...) NSLog(@"%@传入数据有误",__VA_ARGS__)
#else
#define                                         DLOG(...)
#define                                         DLOG_METHOD
#define                                         DLOGERROR(...) NSLog(@"%@传入数据有误",__VA_ARGS__)
#endif

#pragma mark - 判断系统版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define IS_OS_5_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 5.0)
#define IS_OS_6_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0)
#define IS_OS_7_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
//判断是否大于 IOS7
#define IS_IOS7 SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"9.0")

//======================================================================

#define IS_iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)) : NO)

#define IS_iPhone6plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)) : NO)

#define IS_IPHONE6PLUS ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && [[UIScreen mainScreen] nativeScale] == 3.0f)

//判断是否是iphone5
#define IS_WIDESCREEN                              ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - (double)568 ) < __DBL_EPSILON__ )
#define IS_IPHONE                                  ( [ [ [ UIDevice currentDevice ] model ] isEqualToString: @"iPhone" ] || [ [ [ UIDevice currentDevice ] model ] isEqualToString: @"iPhone Simulator" ])
#define IS_IPOD                                    ( [ [ [ UIDevice currentDevice ] model ] isEqualToString: @"iPod touch" ] )
#define IS_IPHONE_5                                ( IS_IPHONE && IS_WIDESCREEN )


#ifndef kCFCoreFoundationVersionNumber_iOS_7_0
#define kCFCoreFoundationVersionNumber_iOS_7_0 838.00
#endif

#define iOS7 (kCFCoreFoundationVersionNumber >= kCFCoreFoundationVersionNumber_iOS_7_0)

#define IOS9 [[UIDevice currentDevice].systemVersion doubleValue] >= 9.0

#define iPhone_X  ((int)([UIScreen mainScreen].bounds.size.height ==812 || [UIScreen mainScreen].bounds.size.height == 896))

#define isiPhoneXStyle ((ScreenHeight == 812.f || ScreenHeight == 896.f) ? YES : NO)

#define tabbar_height (isiPhoneXStyle ? 83.f : 49.f)

#define jian_height (isiPhoneXStyle ? 34.f : 0.f)

#define status_height (isiPhoneXStyle ? 44.f : 20.f)

#define nav_height (isiPhoneXStyle ? 88.f : 64.f)

#define SYSTEM_VERSION_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


#pragma mark - 强弱引用
/** 弱引用 */
#define KRWeakSelf(type)  __weak __typeof(type) weak##type = type;
/** 强引用 */
#define KRStrongSelf(type)  __strong __typeof(type) type = weak##type;


#pragma mark - image

#define KRIMAGE(icon)  [UIImage imageNamed:icon]

#define KRDEFALUT_IMAGE  KRIMAGE(@"3.png")

#pragma mark - Loding... HUD

#define HUD_LOADING [KRProgressHud showloding];

#define HUD_ERROR(s) [KRProgressHud showErrorWithStatus:s]

#define HUD_SUCCESS(s) [KRProgressHud showSuccessWithStatus:s]

#define HUD_DISMISS [KRProgressHud dismiss];


#pragma mark - 代码简化宏

#define KRLANGGECE(content)                                 NSLocalizedString(content, nil)

// .h
#define singleton_interface(class) +(instancetype) shared##class;
// .m
#define singleton_implementation(class)         \
static class *_instance;                        \
\
+(id) allocWithZone : (struct _NSZone *) zone { \
static dispatch_once_t onceToken;           \
dispatch_once(&onceToken, ^{                \
_instance = [super allocWithZone:zone]; \
});                                         \
\
return _instance;                           \
}                                               \
\
+(instancetype) shared##class                   \
{                                           \
if (_instance == nil) {                     \
_instance = [[class alloc] init];       \
}                                           \
\
return _instance;                            \
}



#pragma mark - 各类判断宏
//判断字符串是否为空
#define IFISNIL(v)                                 (v = (v != nil) ? v : @"")
//判断NSNumber是否为空
#define IFISNILFORNUMBER(v)                        (v = (v != nil) ? v : [NSNumber numberWithInt:0])
//判断是否是字符串
#define IFISSTR(v)                                 (v = ([v isKindOfClass:[NSString class]]) ? v : [NSString stringWithFormat:@"%@",v])


#pragma mark - 下载地址
#define fir_url @"http://www.jappstore.com/mcn50"

#define banner_url @"/front/home/homeChart"



