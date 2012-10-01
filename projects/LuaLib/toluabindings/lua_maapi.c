/*
** Lua binding: lua_maapi
** Generated automatically by tolua 5.1.4 on Mon Oct  1 17:58:54 2012.
*/

#include "tolua.h"

#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
 extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
 int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API int tolua_lua_maapi_open (lua_State* tolua_S);
LUALIB_API int luaopen_lua_maapi (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_longlong (lua_State* tolua_S)
{
 longlong* self = (longlong*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"longlong");
}

/* function: maCheckInterfaceVersion */
static int tolua_lua_maapi_mosync_maCheckInterfaceVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int hash = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maCheckInterfaceVersion(hash);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCheckInterfaceVersion'.",&tolua_err);
 return 0;
#endif
}

/* function: maExit */
static int tolua_lua_maapi_mosync_maExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int result = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  maExit(result);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maExit'.",&tolua_err);
 return 0;
#endif
}

/* function: maPanic */
static int tolua_lua_maapi_mosync_maPanic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int result = ((int)  tolua_tonumber(tolua_S,1,0));
  const char* message = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  maPanic(result,message);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPanic'.",&tolua_err);
 return 0;
#endif
}

/* function: memset */
static int tolua_lua_maapi_mosync_memset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* dst = ((void*)  tolua_touserdata(tolua_S,1,0));
  int val = ((int)  tolua_tonumber(tolua_S,2,0));
  ulong size = ((ulong)  tolua_tonumber(tolua_S,3,0));
 {
  void* tolua_ret = (void*)  memset(dst,val,size);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'memset'.",&tolua_err);
 return 0;
#endif
}

/* function: memcpy */
static int tolua_lua_maapi_mosync_memcpy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* dst = ((void*)  tolua_touserdata(tolua_S,1,0));
  const void* src = ((const void*)  tolua_touserdata(tolua_S,2,0));
  ulong size = ((ulong)  tolua_tonumber(tolua_S,3,0));
 {
  void* tolua_ret = (void*)  memcpy(dst,src,size);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'memcpy'.",&tolua_err);
 return 0;
#endif
}

/* function: strcmp */
static int tolua_lua_maapi_mosync_strcmp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* str1 = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* str2 = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  int tolua_ret = (int)  strcmp(str1,str2);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'strcmp'.",&tolua_err);
 return 0;
#endif
}

/* function: strcpy */
static int tolua_lua_maapi_mosync_strcpy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* dst = ((void*)  tolua_touserdata(tolua_S,1,0));
  const char* src = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  char* tolua_ret = (char*)  strcpy(dst,src);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'strcpy'.",&tolua_err);
 return 0;
#endif
}

/* function: __adddf3 */
static int tolua_lua_maapi_mosync___adddf300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
  double b = ((double)  tolua_tonumber(tolua_S,2,0));
 {
  double tolua_ret = (double)  __adddf3(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__adddf3'.",&tolua_err);
 return 0;
#endif
}

/* function: __subdf3 */
static int tolua_lua_maapi_mosync___subdf300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
  double b = ((double)  tolua_tonumber(tolua_S,2,0));
 {
  double tolua_ret = (double)  __subdf3(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__subdf3'.",&tolua_err);
 return 0;
#endif
}

/* function: __muldf3 */
static int tolua_lua_maapi_mosync___muldf300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
  double b = ((double)  tolua_tonumber(tolua_S,2,0));
 {
  double tolua_ret = (double)  __muldf3(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__muldf3'.",&tolua_err);
 return 0;
#endif
}

/* function: __divdf3 */
static int tolua_lua_maapi_mosync___divdf300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
  double b = ((double)  tolua_tonumber(tolua_S,2,0));
 {
  double tolua_ret = (double)  __divdf3(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__divdf3'.",&tolua_err);
 return 0;
#endif
}

/* function: __negdf2 */
static int tolua_lua_maapi_mosync___negdf200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
 {
  double tolua_ret = (double)  __negdf2(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__negdf2'.",&tolua_err);
 return 0;
#endif
}

/* function: __fixdfsi */
static int tolua_lua_maapi_mosync___fixdfsi00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  __fixdfsi(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__fixdfsi'.",&tolua_err);
 return 0;
#endif
}

/* function: __fixunsdfsi */
static int tolua_lua_maapi_mosync___fixunsdfsi00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
 {
  uint tolua_ret = (uint)  __fixunsdfsi(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__fixunsdfsi'.",&tolua_err);
 return 0;
#endif
}

/* function: __floatsidf */
static int tolua_lua_maapi_mosync___floatsidf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  double tolua_ret = (double)  __floatsidf(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__floatsidf'.",&tolua_err);
 return 0;
#endif
}

/* function: __extendsfdf2 */
static int tolua_lua_maapi_mosync___extendsfdf200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  double tolua_ret = (double)  __extendsfdf2(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__extendsfdf2'.",&tolua_err);
 return 0;
#endif
}

/* function: dcmp */
static int tolua_lua_maapi_mosync_dcmp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
  double b = ((double)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  dcmp(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dcmp'.",&tolua_err);
 return 0;
#endif
}

/* function: __addsf3 */
static int tolua_lua_maapi_mosync___addsf300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
  float b = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  __addsf3(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__addsf3'.",&tolua_err);
 return 0;
#endif
}

/* function: __subsf3 */
static int tolua_lua_maapi_mosync___subsf300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
  float b = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  __subsf3(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__subsf3'.",&tolua_err);
 return 0;
#endif
}

/* function: __mulsf3 */
static int tolua_lua_maapi_mosync___mulsf300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
  float b = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  __mulsf3(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__mulsf3'.",&tolua_err);
 return 0;
#endif
}

/* function: __divsf3 */
static int tolua_lua_maapi_mosync___divsf300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
  float b = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  __divsf3(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__divsf3'.",&tolua_err);
 return 0;
#endif
}

/* function: __negsf2 */
static int tolua_lua_maapi_mosync___negsf200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  __negsf2(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__negsf2'.",&tolua_err);
 return 0;
#endif
}

/* function: __fixsfsi */
static int tolua_lua_maapi_mosync___fixsfsi00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  __fixsfsi(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__fixsfsi'.",&tolua_err);
 return 0;
#endif
}

/* function: __fixunssfsi */
static int tolua_lua_maapi_mosync___fixunssfsi00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
 {
  uint tolua_ret = (uint)  __fixunssfsi(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__fixunssfsi'.",&tolua_err);
 return 0;
#endif
}

/* function: __floatsisf */
static int tolua_lua_maapi_mosync___floatsisf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  __floatsisf(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__floatsisf'.",&tolua_err);
 return 0;
#endif
}

/* function: __truncdfsf2 */
static int tolua_lua_maapi_mosync___truncdfsf200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double a = ((double)  tolua_tonumber(tolua_S,1,0));
 {
  float tolua_ret = (float)  __truncdfsf2(a);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '__truncdfsf2'.",&tolua_err);
 return 0;
#endif
}

/* function: fcmp */
static int tolua_lua_maapi_mosync_fcmp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
  float b = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  fcmp(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fcmp'.",&tolua_err);
 return 0;
#endif
}

/* function: sin */
static int tolua_lua_maapi_mosync_sin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double x = ((double)  tolua_tonumber(tolua_S,1,0));
 {
  double tolua_ret = (double)  sin(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sin'.",&tolua_err);
 return 0;
#endif
}

/* function: cos */
static int tolua_lua_maapi_mosync_cos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double x = ((double)  tolua_tonumber(tolua_S,1,0));
 {
  double tolua_ret = (double)  cos(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cos'.",&tolua_err);
 return 0;
#endif
}

/* function: tan */
static int tolua_lua_maapi_mosync_tan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double x = ((double)  tolua_tonumber(tolua_S,1,0));
 {
  double tolua_ret = (double)  tan(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tan'.",&tolua_err);
 return 0;
#endif
}

/* function: sqrt */
static int tolua_lua_maapi_mosync_sqrt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  double x = ((double)  tolua_tonumber(tolua_S,1,0));
 {
  double tolua_ret = (double)  sqrt(x);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sqrt'.",&tolua_err);
 return 0;
#endif
}

/* function: maSetColor */
static int tolua_lua_maapi_mosync_maSetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int rgb = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maSetColor(rgb);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSetColor'.",&tolua_err);
 return 0;
#endif
}

/* function: maSetClipRect */
static int tolua_lua_maapi_mosync_maSetClipRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int left = ((int)  tolua_tonumber(tolua_S,1,0));
  int top = ((int)  tolua_tonumber(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maSetClipRect(left,top,width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSetClipRect'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetClipRect */
static int tolua_lua_maapi_mosync_maGetClipRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* out = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  maGetClipRect(out);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetClipRect'.",&tolua_err);
 return 0;
#endif
}

/* function: maPlot */
static int tolua_lua_maapi_mosync_maPlot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int posX = ((int)  tolua_tonumber(tolua_S,1,0));
  int posY = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  maPlot(posX,posY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPlot'.",&tolua_err);
 return 0;
#endif
}

/* function: maLine */
static int tolua_lua_maapi_mosync_maLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int startX = ((int)  tolua_tonumber(tolua_S,1,0));
  int startY = ((int)  tolua_tonumber(tolua_S,2,0));
  int endX = ((int)  tolua_tonumber(tolua_S,3,0));
  int endY = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maLine(startX,startY,endX,endY);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maLine'.",&tolua_err);
 return 0;
#endif
}

/* function: maFillRect */
static int tolua_lua_maapi_mosync_maFillRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int left = ((int)  tolua_tonumber(tolua_S,1,0));
  int top = ((int)  tolua_tonumber(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maFillRect(left,top,width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFillRect'.",&tolua_err);
 return 0;
#endif
}

/* function: maFillTriangleStrip */
static int tolua_lua_maapi_mosync_maFillTriangleStrip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* points = ((const void*)  tolua_touserdata(tolua_S,1,0));
  int count = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  maFillTriangleStrip(points,count);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFillTriangleStrip'.",&tolua_err);
 return 0;
#endif
}

/* function: maFillTriangleFan */
static int tolua_lua_maapi_mosync_maFillTriangleFan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* points = ((const void*)  tolua_touserdata(tolua_S,1,0));
  int count = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  maFillTriangleFan(points,count);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFillTriangleFan'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetTextSize */
static int tolua_lua_maapi_mosync_maGetTextSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  MAExtent tolua_ret = (MAExtent)  maGetTextSize(str);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetTextSize'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetTextSizeW */
static int tolua_lua_maapi_mosync_maGetTextSizeW00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const wchar str = ((const wchar)  tolua_tonumber(tolua_S,1,0));
 {
  MAExtent tolua_ret = (MAExtent)  maGetTextSizeW(&str);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)str);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetTextSizeW'.",&tolua_err);
 return 0;
#endif
}

/* function: maDrawText */
static int tolua_lua_maapi_mosync_maDrawText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int left = ((int)  tolua_tonumber(tolua_S,1,0));
  int top = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* str = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  maDrawText(left,top,str);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDrawText'.",&tolua_err);
 return 0;
#endif
}

/* function: maDrawTextW */
static int tolua_lua_maapi_mosync_maDrawTextW00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int left = ((int)  tolua_tonumber(tolua_S,1,0));
  int top = ((int)  tolua_tonumber(tolua_S,2,0));
  const wchar str = ((const wchar)  tolua_tonumber(tolua_S,3,0));
 {
  maDrawTextW(left,top,&str);
 tolua_pushnumber(tolua_S,(lua_Number)str);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDrawTextW'.",&tolua_err);
 return 0;
#endif
}

/* function: maUpdateScreen */
static int tolua_lua_maapi_mosync_maUpdateScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  maUpdateScreen();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maUpdateScreen'.",&tolua_err);
 return 0;
#endif
}

/* function: maResetBacklight */
static int tolua_lua_maapi_mosync_maResetBacklight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  maResetBacklight();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maResetBacklight'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetScrSize */
static int tolua_lua_maapi_mosync_maGetScrSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  MAExtent tolua_ret = (MAExtent)  maGetScrSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetScrSize'.",&tolua_err);
 return 0;
#endif
}

/* function: maDrawImage */
static int tolua_lua_maapi_mosync_maDrawImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle image = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  maDrawImage(image,left,top);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDrawImage'.",&tolua_err);
 return 0;
#endif
}

/* function: maDrawRGB */
static int tolua_lua_maapi_mosync_maDrawRGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* dstPoint = ((const void*)  tolua_touserdata(tolua_S,1,0));
  const void* src = ((const void*)  tolua_touserdata(tolua_S,2,0));
  const void* srcRect = ((const void*)  tolua_touserdata(tolua_S,3,0));
  int scanlength = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maDrawRGB(dstPoint,src,srcRect,scanlength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDrawRGB'.",&tolua_err);
 return 0;
#endif
}

/* function: maDrawImageRegion */
static int tolua_lua_maapi_mosync_maDrawImageRegion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle image = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* srcRect = ((const void*)  tolua_touserdata(tolua_S,2,0));
  const void* dstPoint = ((const void*)  tolua_touserdata(tolua_S,3,0));
  int transformMode = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maDrawImageRegion(image,srcRect,dstPoint,transformMode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDrawImageRegion'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetImageSize */
static int tolua_lua_maapi_mosync_maGetImageSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle image = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  MAExtent tolua_ret = (MAExtent)  maGetImageSize(image);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetImageSize'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetImageData */
static int tolua_lua_maapi_mosync_maGetImageData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle image = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,2,0));
  const void* srcRect = ((const void*)  tolua_touserdata(tolua_S,3,0));
  int scanlength = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maGetImageData(image,dst,srcRect,scanlength);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetImageData'.",&tolua_err);
 return 0;
#endif
}

/* function: maSetDrawTarget */
static int tolua_lua_maapi_mosync_maSetDrawTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle image = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  MAHandle tolua_ret = (MAHandle)  maSetDrawTarget(image);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSetDrawTarget'.",&tolua_err);
 return 0;
#endif
}

/* function: maFindLabel */
static int tolua_lua_maapi_mosync_maFindLabel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFindLabel(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFindLabel'.",&tolua_err);
 return 0;
#endif
}

/* function: maCreateImageFromData */
static int tolua_lua_maapi_mosync_maCreateImageFromData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle placeholder = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maCreateImageFromData(placeholder,data,offset,size);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCreateImageFromData'.",&tolua_err);
 return 0;
#endif
}

/* function: maCreateImageRaw */
static int tolua_lua_maapi_mosync_maCreateImageRaw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle placeholder = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* src = ((const void*)  tolua_touserdata(tolua_S,2,0));
  MAExtent size = ((MAExtent)  tolua_tonumber(tolua_S,3,0));
  int alpha = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maCreateImageRaw(placeholder,src,size,alpha);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCreateImageRaw'.",&tolua_err);
 return 0;
#endif
}

/* function: maCreateDrawableImage */
static int tolua_lua_maapi_mosync_maCreateDrawableImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle placeholder = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maCreateDrawableImage(placeholder,width,height);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCreateDrawableImage'.",&tolua_err);
 return 0;
#endif
}

/* function: maCreateData */
static int tolua_lua_maapi_mosync_maCreateData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle placeholder = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maCreateData(placeholder,size);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCreateData'.",&tolua_err);
 return 0;
#endif
}

/* function: maCreatePlaceholder */
static int tolua_lua_maapi_mosync_maCreatePlaceholder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  MAHandle tolua_ret = (MAHandle)  maCreatePlaceholder();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCreatePlaceholder'.",&tolua_err);
 return 0;
#endif
}

/* function: maDestroyPlaceholder */
static int tolua_lua_maapi_mosync_maDestroyPlaceholder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle handle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maDestroyPlaceholder(handle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDestroyPlaceholder'.",&tolua_err);
 return 0;
#endif
}

/* function: maDestroyObject */
static int tolua_lua_maapi_mosync_maDestroyObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle handle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maDestroyObject(handle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDestroyObject'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetDataSize */
static int tolua_lua_maapi_mosync_maGetDataSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maGetDataSize(data);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetDataSize'.",&tolua_err);
 return 0;
#endif
}

/* function: maReadData */
static int tolua_lua_maapi_mosync_maReadData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,2,0));
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maReadData(data,dst,offset,size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maReadData'.",&tolua_err);
 return 0;
#endif
}

/* function: maWriteData */
static int tolua_lua_maapi_mosync_maWriteData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* src = ((const void*)  tolua_touserdata(tolua_S,2,0));
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maWriteData(data,src,offset,size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWriteData'.",&tolua_err);
 return 0;
#endif
}

/* function: maCopyData */
static int tolua_lua_maapi_mosync_maCopyData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* params = ((const void*)  tolua_touserdata(tolua_S,1,0));
 {
  maCopyData(params);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCopyData'.",&tolua_err);
 return 0;
#endif
}

/* function: maOpenStore */
static int tolua_lua_maapi_mosync_maOpenStore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
  int flags = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAHandle tolua_ret = (MAHandle)  maOpenStore(name,flags);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maOpenStore'.",&tolua_err);
 return 0;
#endif
}

/* function: maWriteStore */
static int tolua_lua_maapi_mosync_maWriteStore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle store = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maWriteStore(store,data);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWriteStore'.",&tolua_err);
 return 0;
#endif
}

/* function: maReadStore */
static int tolua_lua_maapi_mosync_maReadStore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle store = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle placeholder = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maReadStore(store,placeholder);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maReadStore'.",&tolua_err);
 return 0;
#endif
}

/* function: maCloseStore */
static int tolua_lua_maapi_mosync_maCloseStore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle store = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int _delete = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  maCloseStore(store,_delete);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCloseStore'.",&tolua_err);
 return 0;
#endif
}

/* function: maConnect */
static int tolua_lua_maapi_mosync_maConnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  MAHandle tolua_ret = (MAHandle)  maConnect(url);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maConnect'.",&tolua_err);
 return 0;
#endif
}

/* function: maConnClose */
static int tolua_lua_maapi_mosync_maConnClose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maConnClose(conn);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maConnClose'.",&tolua_err);
 return 0;
#endif
}

/* function: maConnRead */
static int tolua_lua_maapi_mosync_maConnRead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  maConnRead(conn,dst,size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maConnRead'.",&tolua_err);
 return 0;
#endif
}

/* function: maConnWrite */
static int tolua_lua_maapi_mosync_maConnWrite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* src = ((const void*)  tolua_touserdata(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  maConnWrite(conn,src,size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maConnWrite'.",&tolua_err);
 return 0;
#endif
}

/* function: maConnReadToData */
static int tolua_lua_maapi_mosync_maConnReadToData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maConnReadToData(conn,data,offset,size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maConnReadToData'.",&tolua_err);
 return 0;
#endif
}

/* function: maConnWriteFromData */
static int tolua_lua_maapi_mosync_maConnWriteFromData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  maConnWriteFromData(conn,data,offset,size);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maConnWriteFromData'.",&tolua_err);
 return 0;
#endif
}

/* function: maConnGetAddr */
static int tolua_lua_maapi_mosync_maConnGetAddr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* addr = ((void*)  tolua_touserdata(tolua_S,2,0));
 {
  int tolua_ret = (int)  maConnGetAddr(conn,addr);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maConnGetAddr'.",&tolua_err);
 return 0;
#endif
}

/* function: maHttpCreate */
static int tolua_lua_maapi_mosync_maHttpCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,1,0));
  int method = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAHandle tolua_ret = (MAHandle)  maHttpCreate(url,method);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maHttpCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: maHttpSetRequestHeader */
static int tolua_lua_maapi_mosync_maHttpSetRequestHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  maHttpSetRequestHeader(conn,key,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maHttpSetRequestHeader'.",&tolua_err);
 return 0;
#endif
}

/* function: maHttpGetResponseHeader */
static int tolua_lua_maapi_mosync_maHttpGetResponseHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  void* buffer = ((void*)  tolua_touserdata(tolua_S,3,0));
  int bufSize = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maHttpGetResponseHeader(conn,key,buffer,bufSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maHttpGetResponseHeader'.",&tolua_err);
 return 0;
#endif
}

/* function: maHttpFinish */
static int tolua_lua_maapi_mosync_maHttpFinish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle conn = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maHttpFinish(conn);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maHttpFinish'.",&tolua_err);
 return 0;
#endif
}

/* function: maLoadResources */
static int tolua_lua_maapi_mosync_maLoadResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maLoadResources(data);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maLoadResources'.",&tolua_err);
 return 0;
#endif
}

/* function: maLoadResource */
static int tolua_lua_maapi_mosync_maLoadResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle handle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle placeholder = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
  int flag = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maLoadResource(handle,placeholder,flag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maLoadResource'.",&tolua_err);
 return 0;
#endif
}

/* function: maCountResources */
static int tolua_lua_maapi_mosync_maCountResources00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maCountResources();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCountResources'.",&tolua_err);
 return 0;
#endif
}

/* function: maLoadProgram */
static int tolua_lua_maapi_mosync_maLoadProgram00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int reload = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  maLoadProgram(data,reload);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maLoadProgram'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetKeys */
static int tolua_lua_maapi_mosync_maGetKeys00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maGetKeys();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetKeys'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetEvent */
static int tolua_lua_maapi_mosync_maGetEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  maGetEvent(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetEvent'.",&tolua_err);
 return 0;
#endif
}

/* function: maWait */
static int tolua_lua_maapi_mosync_maWait00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int timeout = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  maWait(timeout);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWait'.",&tolua_err);
 return 0;
#endif
}

/* function: maTime */
static int tolua_lua_maapi_mosync_maTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maTime'.",&tolua_err);
 return 0;
#endif
}

/* function: maLocalTime */
static int tolua_lua_maapi_mosync_maLocalTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maLocalTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maLocalTime'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetMilliSecondCount */
static int tolua_lua_maapi_mosync_maGetMilliSecondCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maGetMilliSecondCount();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetMilliSecondCount'.",&tolua_err);
 return 0;
#endif
}

/* function: maFreeObjectMemory */
static int tolua_lua_maapi_mosync_maFreeObjectMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maFreeObjectMemory();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFreeObjectMemory'.",&tolua_err);
 return 0;
#endif
}

/* function: maTotalObjectMemory */
static int tolua_lua_maapi_mosync_maTotalObjectMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maTotalObjectMemory();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maTotalObjectMemory'.",&tolua_err);
 return 0;
#endif
}

/* function: maVibrate */
static int tolua_lua_maapi_mosync_maVibrate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int ms = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maVibrate(ms);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maVibrate'.",&tolua_err);
 return 0;
#endif
}

/* function: maSoundPlay */
static int tolua_lua_maapi_mosync_maSoundPlay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle sound_res = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int offset = ((int)  tolua_tonumber(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maSoundPlay(sound_res,offset,size);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSoundPlay'.",&tolua_err);
 return 0;
#endif
}

/* function: maSoundStop */
static int tolua_lua_maapi_mosync_maSoundStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  maSoundStop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSoundStop'.",&tolua_err);
 return 0;
#endif
}

/* function: maSoundIsPlaying */
static int tolua_lua_maapi_mosync_maSoundIsPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maSoundIsPlaying();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSoundIsPlaying'.",&tolua_err);
 return 0;
#endif
}

/* function: maSoundGetVolume */
static int tolua_lua_maapi_mosync_maSoundGetVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maSoundGetVolume();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSoundGetVolume'.",&tolua_err);
 return 0;
#endif
}

/* function: maSoundSetVolume */
static int tolua_lua_maapi_mosync_maSoundSetVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int vol = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  maSoundSetVolume(vol);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSoundSetVolume'.",&tolua_err);
 return 0;
#endif
}

/* function: maExtensionFunctionInvoke */
static int tolua_lua_maapi_mosync_maExtensionFunctionInvoke00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int function = ((int)  tolua_tonumber(tolua_S,1,0));
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
  int b = ((int)  tolua_tonumber(tolua_S,3,0));
  int c = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  longlong tolua_ret =  maExtensionFunctionInvoke(function,a,b,c);
 {
#ifdef __cplusplus
 void* tolua_obj = new longlong(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_longlong),"longlong");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(longlong));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"longlong");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maExtensionFunctionInvoke'.",&tolua_err);
 return 0;
#endif
}

/* function: maExtensionModuleLoad */
static int tolua_lua_maapi_mosync_maExtensionModuleLoad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* id = ((const char*)  tolua_tostring(tolua_S,1,0));
  int hash = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAExtensionModule tolua_ret = (MAExtensionModule)  maExtensionModuleLoad(id,hash);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maExtensionModuleLoad'.",&tolua_err);
 return 0;
#endif
}

/* function: maExtensionFunctionLoad */
static int tolua_lua_maapi_mosync_maExtensionFunctionLoad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAExtensionModule module = ((MAExtensionModule)  tolua_tonumber(tolua_S,1,0));
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAExtensionFunction tolua_ret = (MAExtensionFunction)  maExtensionFunctionLoad(module,index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maExtensionFunctionLoad'.",&tolua_err);
 return 0;
#endif
}

/* function: maFontLoadDefault */
static int tolua_lua_maapi_mosync_maFontLoadDefault00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int type = ((int)  tolua_tonumber(tolua_S,1,0));
  int style = ((int)  tolua_tonumber(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  MAHandle tolua_ret = (MAHandle)  maFontLoadDefault(type,style,size);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFontLoadDefault'.",&tolua_err);
 return 0;
#endif
}

/* function: maFontSetCurrent */
static int tolua_lua_maapi_mosync_maFontSetCurrent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle font = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  MAHandle tolua_ret = (MAHandle)  maFontSetCurrent(font);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFontSetCurrent'.",&tolua_err);
 return 0;
#endif
}

/* function: maFontGetCount */
static int tolua_lua_maapi_mosync_maFontGetCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maFontGetCount();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFontGetCount'.",&tolua_err);
 return 0;
#endif
}

/* function: maFontGetName */
static int tolua_lua_maapi_mosync_maFontGetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int index = ((int)  tolua_tonumber(tolua_S,1,0));
  void* buffer = ((void*)  tolua_touserdata(tolua_S,2,0));
  int bufferLen = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maFontGetName(index,buffer,bufferLen);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFontGetName'.",&tolua_err);
 return 0;
#endif
}

/* function: maFontLoadWithName */
static int tolua_lua_maapi_mosync_maFontLoadWithName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* postScriptName = ((const char*)  tolua_tostring(tolua_S,1,0));
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAHandle tolua_ret = (MAHandle)  maFontLoadWithName(postScriptName,size);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFontLoadWithName'.",&tolua_err);
 return 0;
#endif
}

/* function: maFontDelete */
static int tolua_lua_maapi_mosync_maFontDelete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle font = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFontDelete(font);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFontDelete'.",&tolua_err);
 return 0;
#endif
}

/* function: maReportCallStack */
static int tolua_lua_maapi_mosync_maReportCallStack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maReportCallStack();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maReportCallStack'.",&tolua_err);
 return 0;
#endif
}

/* function: maDumpCallStackEx */
static int tolua_lua_maapi_mosync_maDumpCallStackEx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,1,0));
  int data = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maDumpCallStackEx(str,data);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDumpCallStackEx'.",&tolua_err);
 return 0;
#endif
}

/* function: maProtectMemory */
static int tolua_lua_maapi_mosync_maProtectMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* start = ((const void*)  tolua_touserdata(tolua_S,1,0));
  int length = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  maProtectMemory(start,length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maProtectMemory'.",&tolua_err);
 return 0;
#endif
}

/* function: maUnprotectMemory */
static int tolua_lua_maapi_mosync_maUnprotectMemory00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* start = ((const void*)  tolua_touserdata(tolua_S,1,0));
  int length = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  maUnprotectMemory(start,length);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maUnprotectMemory'.",&tolua_err);
 return 0;
#endif
}

/* function: maSetMemoryProtection */
static int tolua_lua_maapi_mosync_maSetMemoryProtection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int enable = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  maSetMemoryProtection(enable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSetMemoryProtection'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetMemoryProtection */
static int tolua_lua_maapi_mosync_maGetMemoryProtection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maGetMemoryProtection();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetMemoryProtection'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetBatteryCharge */
static int tolua_lua_maapi_mosync_maGetBatteryCharge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maGetBatteryCharge();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetBatteryCharge'.",&tolua_err);
 return 0;
#endif
}

/* function: maLockKeypad */
static int tolua_lua_maapi_mosync_maLockKeypad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maLockKeypad();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maLockKeypad'.",&tolua_err);
 return 0;
#endif
}

/* function: maUnlockKeypad */
static int tolua_lua_maapi_mosync_maUnlockKeypad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maUnlockKeypad();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maUnlockKeypad'.",&tolua_err);
 return 0;
#endif
}

/* function: maKeypadIsLocked */
static int tolua_lua_maapi_mosync_maKeypadIsLocked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maKeypadIsLocked();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maKeypadIsLocked'.",&tolua_err);
 return 0;
#endif
}

/* function: maWriteLog */
static int tolua_lua_maapi_mosync_maWriteLog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* src = ((const void*)  tolua_touserdata(tolua_S,1,0));
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maWriteLog(src,size);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWriteLog'.",&tolua_err);
 return 0;
#endif
}

/* function: maBtStartDeviceDiscovery */
static int tolua_lua_maapi_mosync_maBtStartDeviceDiscovery00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int names = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maBtStartDeviceDiscovery(names);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maBtStartDeviceDiscovery'.",&tolua_err);
 return 0;
#endif
}

/* function: maBtGetNewDevice */
static int tolua_lua_maapi_mosync_maBtGetNewDevice00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* d = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  maBtGetNewDevice(d);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maBtGetNewDevice'.",&tolua_err);
 return 0;
#endif
}

/* function: maBtStartServiceDiscovery */
static int tolua_lua_maapi_mosync_maBtStartServiceDiscovery00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* address = ((const void*)  tolua_touserdata(tolua_S,1,0));
  const void* uuid = ((const void*)  tolua_touserdata(tolua_S,2,0));
 {
  int tolua_ret = (int)  maBtStartServiceDiscovery(address,uuid);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maBtStartServiceDiscovery'.",&tolua_err);
 return 0;
#endif
}

/* function: maBtGetNextServiceSize */
static int tolua_lua_maapi_mosync_maBtGetNextServiceSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* dst = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  maBtGetNextServiceSize(dst);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maBtGetNextServiceSize'.",&tolua_err);
 return 0;
#endif
}

/* function: maBtGetNewService */
static int tolua_lua_maapi_mosync_maBtGetNewService00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* dst = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  maBtGetNewService(dst);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maBtGetNewService'.",&tolua_err);
 return 0;
#endif
}

/* function: maBtCancelDiscovery */
static int tolua_lua_maapi_mosync_maBtCancelDiscovery00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maBtCancelDiscovery();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maBtCancelDiscovery'.",&tolua_err);
 return 0;
#endif
}

/* function: maLocationStart */
static int tolua_lua_maapi_mosync_maLocationStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maLocationStart();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maLocationStart'.",&tolua_err);
 return 0;
#endif
}

/* function: maLocationStop */
static int tolua_lua_maapi_mosync_maLocationStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maLocationStop();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maLocationStop'.",&tolua_err);
 return 0;
#endif
}

/* function: maPlatformRequest */
static int tolua_lua_maapi_mosync_maPlatformRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  int tolua_ret = (int)  maPlatformRequest(url);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPlatformRequest'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileOpen */
static int tolua_lua_maapi_mosync_maFileOpen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAHandle tolua_ret = (MAHandle)  maFileOpen(path,mode);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileOpen'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileExists */
static int tolua_lua_maapi_mosync_maFileExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileExists(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileExists'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileClose */
static int tolua_lua_maapi_mosync_maFileClose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileClose(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileClose'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileCreate */
static int tolua_lua_maapi_mosync_maFileCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileCreate(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileDelete */
static int tolua_lua_maapi_mosync_maFileDelete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileDelete(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileDelete'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileSize */
static int tolua_lua_maapi_mosync_maFileSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileSize(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileSize'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileAvailableSpace */
static int tolua_lua_maapi_mosync_maFileAvailableSpace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileAvailableSpace(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileAvailableSpace'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileTotalSpace */
static int tolua_lua_maapi_mosync_maFileTotalSpace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileTotalSpace(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileTotalSpace'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileDate */
static int tolua_lua_maapi_mosync_maFileDate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileDate(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileDate'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileRename */
static int tolua_lua_maapi_mosync_maFileRename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* newName = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  int tolua_ret = (int)  maFileRename(file,newName);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileRename'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileTruncate */
static int tolua_lua_maapi_mosync_maFileTruncate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int offset = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maFileTruncate(file,offset);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileTruncate'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileWrite */
static int tolua_lua_maapi_mosync_maFileWrite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* src = ((const void*)  tolua_touserdata(tolua_S,2,0));
  int len = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maFileWrite(file,src,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileWrite'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileWriteFromData */
static int tolua_lua_maapi_mosync_maFileWriteFromData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
  int len = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maFileWriteFromData(file,data,offset,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileWriteFromData'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileRead */
static int tolua_lua_maapi_mosync_maFileRead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,2,0));
  int len = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maFileRead(file,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileRead'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileReadToData */
static int tolua_lua_maapi_mosync_maFileReadToData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
  int len = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maFileReadToData(file,data,offset,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileReadToData'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileTell */
static int tolua_lua_maapi_mosync_maFileTell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileTell(file);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileTell'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileSeek */
static int tolua_lua_maapi_mosync_maFileSeek00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle file = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int offset = ((int)  tolua_tonumber(tolua_S,2,0));
  int whence = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maFileSeek(file,offset,whence);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileSeek'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileListStart */
static int tolua_lua_maapi_mosync_maFileListStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* filter = ((const char*)  tolua_tostring(tolua_S,2,0));
  int sorting = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  MAHandle tolua_ret = (MAHandle)  maFileListStart(path,filter,sorting);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileListStart'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileListNext */
static int tolua_lua_maapi_mosync_maFileListNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle list = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* nameBuf = ((void*)  tolua_touserdata(tolua_S,2,0));
  int bufSize = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maFileListNext(list,nameBuf,bufSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileListNext'.",&tolua_err);
 return 0;
#endif
}

/* function: maFileListClose */
static int tolua_lua_maapi_mosync_maFileListClose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle list = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFileListClose(list);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFileListClose'.",&tolua_err);
 return 0;
#endif
}

/* function: maSendTextSMS */
static int tolua_lua_maapi_mosync_maSendTextSMS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* dst = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* msg = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  int tolua_ret = (int)  maSendTextSMS(dst,msg);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSendTextSMS'.",&tolua_err);
 return 0;
#endif
}

/* function: maFrameBufferGetInfo */
static int tolua_lua_maapi_mosync_maFrameBufferGetInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* info = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFrameBufferGetInfo(info);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFrameBufferGetInfo'.",&tolua_err);
 return 0;
#endif
}

/* function: maFrameBufferInit */
static int tolua_lua_maapi_mosync_maFrameBufferInit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* data = ((const void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  maFrameBufferInit(data);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFrameBufferInit'.",&tolua_err);
 return 0;
#endif
}

/* function: maFrameBufferClose */
static int tolua_lua_maapi_mosync_maFrameBufferClose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maFrameBufferClose();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maFrameBufferClose'.",&tolua_err);
 return 0;
#endif
}

/* function: maAccept */
static int tolua_lua_maapi_mosync_maAccept00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle serv = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAccept(serv);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAccept'.",&tolua_err);
 return 0;
#endif
}

/* function: maSendToBackground */
static int tolua_lua_maapi_mosync_maSendToBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maSendToBackground();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSendToBackground'.",&tolua_err);
 return 0;
#endif
}

/* function: maBringToForeground */
static int tolua_lua_maapi_mosync_maBringToForeground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maBringToForeground();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maBringToForeground'.",&tolua_err);
 return 0;
#endif
}

/* function: maGetSystemProperty */
static int tolua_lua_maapi_mosync_maGetSystemProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* key = ((const char*)  tolua_tostring(tolua_S,1,0));
  void* buf = ((void*)  tolua_touserdata(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maGetSystemProperty(key,buf,size);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maGetSystemProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maIapSave */
static int tolua_lua_maapi_mosync_maIapSave00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maIapSave();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maIapSave'.",&tolua_err);
 return 0;
#endif
}

/* function: maIapReset */
static int tolua_lua_maapi_mosync_maIapReset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maIapReset();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maIapReset'.",&tolua_err);
 return 0;
#endif
}

/* function: maIapShutdown */
static int tolua_lua_maapi_mosync_maIapShutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maIapShutdown();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maIapShutdown'.",&tolua_err);
 return 0;
#endif
}

/* function: maNetworkStatus */
static int tolua_lua_maapi_mosync_maNetworkStatus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maNetworkStatus();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNetworkStatus'.",&tolua_err);
 return 0;
#endif
}

/* function: maIapSetMethod */
static int tolua_lua_maapi_mosync_maIapSetMethod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int type = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maIapSetMethod(type);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maIapSetMethod'.",&tolua_err);
 return 0;
#endif
}

/* function: maIapSetFilter */
static int tolua_lua_maapi_mosync_maIapSetFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int filter = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maIapSetFilter(filter);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maIapSetFilter'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraFormatNumber */
static int tolua_lua_maapi_mosync_maCameraFormatNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maCameraFormatNumber();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraFormatNumber'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraFormat */
static int tolua_lua_maapi_mosync_maCameraFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int index = ((int)  tolua_tonumber(tolua_S,1,0));
  void* fmt = ((void*)  tolua_touserdata(tolua_S,2,0));
 {
  int tolua_ret = (int)  maCameraFormat(index,fmt);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraFormat'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraStart */
static int tolua_lua_maapi_mosync_maCameraStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maCameraStart();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraStart'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraStop */
static int tolua_lua_maapi_mosync_maCameraStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maCameraStop();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraStop'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraSetPreview */
static int tolua_lua_maapi_mosync_maCameraSetPreview00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle widgetHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maCameraSetPreview(widgetHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraSetPreview'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraSelect */
static int tolua_lua_maapi_mosync_maCameraSelect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int cameraNumber = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maCameraSelect(cameraNumber);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraSelect'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraNumber */
static int tolua_lua_maapi_mosync_maCameraNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maCameraNumber();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraNumber'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraSnapshot */
static int tolua_lua_maapi_mosync_maCameraSnapshot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int formatIndex = ((int)  tolua_tonumber(tolua_S,1,0));
  MAHandle placeholder = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maCameraSnapshot(formatIndex,placeholder);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraSnapshot'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraRecord */
static int tolua_lua_maapi_mosync_maCameraRecord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int stopStartFlag = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maCameraRecord(stopStartFlag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraRecord'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraSetProperty */
static int tolua_lua_maapi_mosync_maCameraSetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* property = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  int tolua_ret = (int)  maCameraSetProperty(property,value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraSetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maCameraGetProperty */
static int tolua_lua_maapi_mosync_maCameraGetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* property = ((const char*)  tolua_tostring(tolua_S,1,0));
  void* value = ((void*)  tolua_touserdata(tolua_S,2,0));
  int bufSize = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maCameraGetProperty(property,value,bufSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCameraGetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maShowVirtualKeyboard */
static int tolua_lua_maapi_mosync_maShowVirtualKeyboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maShowVirtualKeyboard();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maShowVirtualKeyboard'.",&tolua_err);
 return 0;
#endif
}

/* function: maTextBox */
static int tolua_lua_maapi_mosync_maTextBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* title = ((const void*)  tolua_touserdata(tolua_S,1,0));
  const void* inText = ((const void*)  tolua_touserdata(tolua_S,2,0));
  void* outText = ((void*)  tolua_touserdata(tolua_S,3,0));
  int maxSize = ((int)  tolua_tonumber(tolua_S,4,0));
  int constraints = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  int tolua_ret = (int)  maTextBox(title,inText,outText,maxSize,constraints);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maTextBox'.",&tolua_err);
 return 0;
#endif
}

/* function: maKeyCaptureStart */
static int tolua_lua_maapi_mosync_maKeyCaptureStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int keyCode = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maKeyCaptureStart(keyCode);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maKeyCaptureStart'.",&tolua_err);
 return 0;
#endif
}

/* function: maKeyCaptureStop */
static int tolua_lua_maapi_mosync_maKeyCaptureStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maKeyCaptureStop();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maKeyCaptureStop'.",&tolua_err);
 return 0;
#endif
}

/* function: maHomeScreenEventsOn */
static int tolua_lua_maapi_mosync_maHomeScreenEventsOn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maHomeScreenEventsOn();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maHomeScreenEventsOn'.",&tolua_err);
 return 0;
#endif
}

/* function: maHomeScreenEventsOff */
static int tolua_lua_maapi_mosync_maHomeScreenEventsOff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maHomeScreenEventsOff();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maHomeScreenEventsOff'.",&tolua_err);
 return 0;
#endif
}

/* function: maHomeScreenShortcutAdd */
static int tolua_lua_maapi_mosync_maHomeScreenShortcutAdd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  int tolua_ret = (int)  maHomeScreenShortcutAdd(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maHomeScreenShortcutAdd'.",&tolua_err);
 return 0;
#endif
}

/* function: maHomeScreenShortcutRemove */
static int tolua_lua_maapi_mosync_maHomeScreenShortcutRemove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  int tolua_ret = (int)  maHomeScreenShortcutRemove(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maHomeScreenShortcutRemove'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationAdd */
static int tolua_lua_maapi_mosync_maNotificationAdd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isstring(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int type = ((int)  tolua_tonumber(tolua_S,1,0));
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* title = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* text = ((const char*)  tolua_tostring(tolua_S,4,0));
 {
  int tolua_ret = (int)  maNotificationAdd(type,id,title,text);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationAdd'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationRemove */
static int tolua_lua_maapi_mosync_maNotificationRemove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int id = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNotificationRemove(id);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationRemove'.",&tolua_err);
 return 0;
#endif
}

/* function: maScreenSetOrientation */
static int tolua_lua_maapi_mosync_maScreenSetOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int orientation = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maScreenSetOrientation(orientation);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maScreenSetOrientation'.",&tolua_err);
 return 0;
#endif
}

/* function: maScreenSetFullscreen */
static int tolua_lua_maapi_mosync_maScreenSetFullscreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int fullscreen = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maScreenSetFullscreen(fullscreen);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maScreenSetFullscreen'.",&tolua_err);
 return 0;
#endif
}

/* function: maAutostartOn */
static int tolua_lua_maapi_mosync_maAutostartOn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maAutostartOn();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAutostartOn'.",&tolua_err);
 return 0;
#endif
}

/* function: maAutostartOff */
static int tolua_lua_maapi_mosync_maAutostartOff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maAutostartOff();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAutostartOff'.",&tolua_err);
 return 0;
#endif
}

/* function: maScreenSetSupportedOrientations */
static int tolua_lua_maapi_mosync_maScreenSetSupportedOrientations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int orientations = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maScreenSetSupportedOrientations(orientations);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maScreenSetSupportedOrientations'.",&tolua_err);
 return 0;
#endif
}

/* function: maScreenGetSupportedOrientations */
static int tolua_lua_maapi_mosync_maScreenGetSupportedOrientations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maScreenGetSupportedOrientations();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maScreenGetSupportedOrientations'.",&tolua_err);
 return 0;
#endif
}

/* function: maScreenGetCurrentOrientation */
static int tolua_lua_maapi_mosync_maScreenGetCurrentOrientation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maScreenGetCurrentOrientation();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maScreenGetCurrentOrientation'.",&tolua_err);
 return 0;
#endif
}

/* function: maScreenStateEventsOn */
static int tolua_lua_maapi_mosync_maScreenStateEventsOn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maScreenStateEventsOn();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maScreenStateEventsOn'.",&tolua_err);
 return 0;
#endif
}

/* function: maScreenStateEventsOff */
static int tolua_lua_maapi_mosync_maScreenStateEventsOff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maScreenStateEventsOff();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maScreenStateEventsOff'.",&tolua_err);
 return 0;
#endif
}

/* function: maWakeLock */
static int tolua_lua_maapi_mosync_maWakeLock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int flag = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maWakeLock(flag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWakeLock'.",&tolua_err);
 return 0;
#endif
}

/* function: maReportResourceInformation */
static int tolua_lua_maapi_mosync_maReportResourceInformation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  maReportResourceInformation();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maReportResourceInformation'.",&tolua_err);
 return 0;
#endif
}

/* function: maMessageBox */
static int tolua_lua_maapi_mosync_maMessageBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* title = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* message = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  maMessageBox(title,message);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maMessageBox'.",&tolua_err);
 return 0;
#endif
}

/* function: maAlert */
static int tolua_lua_maapi_mosync_maAlert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isstring(tolua_S,4,0,&tolua_err) || 
 !tolua_isstring(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* title = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* message = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* button1 = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* button2 = ((const char*)  tolua_tostring(tolua_S,4,0));
  const char* button3 = ((const char*)  tolua_tostring(tolua_S,5,0));
 {
  maAlert(title,message,button1,button2,button3);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAlert'.",&tolua_err);
 return 0;
#endif
}

/* function: maImagePickerOpen */
static int tolua_lua_maapi_mosync_maImagePickerOpen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  maImagePickerOpen();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maImagePickerOpen'.",&tolua_err);
 return 0;
#endif
}

/* function: maOptionsBox */
static int tolua_lua_maapi_mosync_maOptionsBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* title = ((const void*)  tolua_touserdata(tolua_S,1,0));
  const void* destructiveButtonTitle = ((const void*)  tolua_touserdata(tolua_S,2,0));
  const void* cancelButtonTitle = ((const void*)  tolua_touserdata(tolua_S,3,0));
  const void* otherButtonTitles = ((const void*)  tolua_touserdata(tolua_S,4,0));
  int otherButtonTitlesSize = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  maOptionsBox(title,destructiveButtonTitle,cancelButtonTitle,otherButtonTitles,otherButtonTitlesSize);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maOptionsBox'.",&tolua_err);
 return 0;
#endif
}

/* function: maSensorStart */
static int tolua_lua_maapi_mosync_maSensorStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int sensor = ((int)  tolua_tonumber(tolua_S,1,0));
  int interval = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maSensorStart(sensor,interval);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSensorStart'.",&tolua_err);
 return 0;
#endif
}

/* function: maSensorStop */
static int tolua_lua_maapi_mosync_maSensorStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int sensor = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maSensorStop(sensor);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSensorStop'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCStart */
static int tolua_lua_maapi_mosync_maNFCStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maNFCStart();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCStart'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCStop */
static int tolua_lua_maapi_mosync_maNFCStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  maNFCStop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCStop'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCReadTag */
static int tolua_lua_maapi_mosync_maNFCReadTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle nfcContext = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  MAHandle tolua_ret = (MAHandle)  maNFCReadTag(nfcContext);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCReadTag'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCDestroyTag */
static int tolua_lua_maapi_mosync_maNFCDestroyTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maNFCDestroyTag(tagHandle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCDestroyTag'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCConnectTag */
static int tolua_lua_maapi_mosync_maNFCConnectTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maNFCConnectTag(tagHandle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCConnectTag'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCCloseTag */
static int tolua_lua_maapi_mosync_maNFCCloseTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maNFCCloseTag(tagHandle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCCloseTag'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCIsType */
static int tolua_lua_maapi_mosync_maNFCIsType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maNFCIsType(tagHandle,type);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCIsType'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetTypedTag */
static int tolua_lua_maapi_mosync_maNFCGetTypedTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAHandle tolua_ret = (MAHandle)  maNFCGetTypedTag(tagHandle,type);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetTypedTag'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCBatchStart */
static int tolua_lua_maapi_mosync_maNFCBatchStart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCBatchStart(tagHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCBatchStart'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCBatchCommit */
static int tolua_lua_maapi_mosync_maNFCBatchCommit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maNFCBatchCommit(tagHandle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCBatchCommit'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCBatchRollback */
static int tolua_lua_maapi_mosync_maNFCBatchRollback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maNFCBatchRollback(tagHandle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCBatchRollback'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCTransceive */
static int tolua_lua_maapi_mosync_maNFCTransceive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tag = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* src = ((const void*)  tolua_touserdata(tolua_S,2,0));
  int srcLen = ((int)  tolua_tonumber(tolua_S,3,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,4,0));
  int dstLen = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  int tolua_ret = (int)  maNFCTransceive(tag,src,srcLen,dst,&dstLen);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)dstLen);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCTransceive'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCSetReadOnly */
static int tolua_lua_maapi_mosync_maNFCSetReadOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tag = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCSetReadOnly(tag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCSetReadOnly'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCIsReadOnly */
static int tolua_lua_maapi_mosync_maNFCIsReadOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tag = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCIsReadOnly(tag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCIsReadOnly'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetSize */
static int tolua_lua_maapi_mosync_maNFCGetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tag = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCGetSize(tag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetSize'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCReadNDEFMessage */
static int tolua_lua_maapi_mosync_maNFCReadNDEFMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tag = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCReadNDEFMessage(tag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCReadNDEFMessage'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCWriteNDEFMessage */
static int tolua_lua_maapi_mosync_maNFCWriteNDEFMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tag = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle ndefMessage = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maNFCWriteNDEFMessage(tag,ndefMessage);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCWriteNDEFMessage'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCCreateNDEFMessage */
static int tolua_lua_maapi_mosync_maNFCCreateNDEFMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int recordCount = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  MAHandle tolua_ret = (MAHandle)  maNFCCreateNDEFMessage(recordCount);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCCreateNDEFMessage'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetNDEFMessage */
static int tolua_lua_maapi_mosync_maNFCGetNDEFMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tag = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCGetNDEFMessage(tag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetNDEFMessage'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetNDEFRecord */
static int tolua_lua_maapi_mosync_maNFCGetNDEFRecord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefMessage = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int ix = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAHandle tolua_ret = (MAHandle)  maNFCGetNDEFRecord(ndefMessage,ix);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetNDEFRecord'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetNDEFRecordCount */
static int tolua_lua_maapi_mosync_maNFCGetNDEFRecordCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefMessage = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCGetNDEFRecordCount(ndefMessage);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetNDEFRecordCount'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetNDEFId */
static int tolua_lua_maapi_mosync_maNFCGetNDEFId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefRecord = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,2,0));
  int len = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maNFCGetNDEFId(ndefRecord,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetNDEFId'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetNDEFPayload */
static int tolua_lua_maapi_mosync_maNFCGetNDEFPayload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefRecord = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,2,0));
  int len = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maNFCGetNDEFPayload(ndefRecord,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetNDEFPayload'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetNDEFTnf */
static int tolua_lua_maapi_mosync_maNFCGetNDEFTnf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefRecord = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCGetNDEFTnf(ndefRecord);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetNDEFTnf'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetNDEFType */
static int tolua_lua_maapi_mosync_maNFCGetNDEFType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefRecord = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,2,0));
  int len = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maNFCGetNDEFType(ndefRecord,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetNDEFType'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCSetNDEFId */
static int tolua_lua_maapi_mosync_maNFCSetNDEFId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefRecord = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* dst = ((const void*)  tolua_touserdata(tolua_S,2,0));
  int len = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maNFCSetNDEFId(ndefRecord,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCSetNDEFId'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCSetNDEFPayload */
static int tolua_lua_maapi_mosync_maNFCSetNDEFPayload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefRecord = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* dst = ((const void*)  tolua_touserdata(tolua_S,2,0));
  int len = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maNFCSetNDEFPayload(ndefRecord,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCSetNDEFPayload'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCSetNDEFTnf */
static int tolua_lua_maapi_mosync_maNFCSetNDEFTnf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefRecord = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int tnf = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maNFCSetNDEFTnf(ndefRecord,tnf);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCSetNDEFTnf'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCSetNDEFType */
static int tolua_lua_maapi_mosync_maNFCSetNDEFType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle ndefRecord = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const void* dst = ((const void*)  tolua_touserdata(tolua_S,2,0));
  int len = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maNFCSetNDEFType(ndefRecord,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCSetNDEFType'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCAuthenticateMifareSector */
static int tolua_lua_maapi_mosync_maNFCAuthenticateMifareSector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int keyType = ((int)  tolua_tonumber(tolua_S,2,0));
  int sectorIndex = ((int)  tolua_tonumber(tolua_S,3,0));
  const void* keySrc = ((const void*)  tolua_touserdata(tolua_S,4,0));
  int keyLen = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  int tolua_ret = (int)  maNFCAuthenticateMifareSector(tagHandle,keyType,sectorIndex,keySrc,keyLen);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCAuthenticateMifareSector'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetMifareSectorCount */
static int tolua_lua_maapi_mosync_maNFCGetMifareSectorCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNFCGetMifareSectorCount(tagHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetMifareSectorCount'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCGetMifareBlockCountInSector */
static int tolua_lua_maapi_mosync_maNFCGetMifareBlockCountInSector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int sector = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maNFCGetMifareBlockCountInSector(tagHandle,sector);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCGetMifareBlockCountInSector'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCMifareSectorToBlock */
static int tolua_lua_maapi_mosync_maNFCMifareSectorToBlock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int sector = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maNFCMifareSectorToBlock(tagHandle,sector);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCMifareSectorToBlock'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCReadMifareBlocks */
static int tolua_lua_maapi_mosync_maNFCReadMifareBlocks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int firstBlock = ((int)  tolua_tonumber(tolua_S,2,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,3,0));
  int len = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maNFCReadMifareBlocks(tagHandle,firstBlock,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCReadMifareBlocks'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCWriteMifareBlocks */
static int tolua_lua_maapi_mosync_maNFCWriteMifareBlocks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int firstBlock = ((int)  tolua_tonumber(tolua_S,2,0));
  const void* dst = ((const void*)  tolua_touserdata(tolua_S,3,0));
  int len = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maNFCWriteMifareBlocks(tagHandle,firstBlock,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCWriteMifareBlocks'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCReadMifarePages */
static int tolua_lua_maapi_mosync_maNFCReadMifarePages00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int firstPage = ((int)  tolua_tonumber(tolua_S,2,0));
  void* dst = ((void*)  tolua_touserdata(tolua_S,3,0));
  int len = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maNFCReadMifarePages(tagHandle,firstPage,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCReadMifarePages'.",&tolua_err);
 return 0;
#endif
}

/* function: maNFCWriteMifarePages */
static int tolua_lua_maapi_mosync_maNFCWriteMifarePages00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle tagHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int firstPage = ((int)  tolua_tonumber(tolua_S,2,0));
  const void* dst = ((const void*)  tolua_touserdata(tolua_S,3,0));
  int len = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maNFCWriteMifarePages(tagHandle,firstPage,dst,len);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNFCWriteMifarePages'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBOpen */
static int tolua_lua_maapi_mosync_maDBOpen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  MAHandle tolua_ret = (MAHandle)  maDBOpen(path);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBOpen'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBClose */
static int tolua_lua_maapi_mosync_maDBClose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle databaseHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maDBClose(databaseHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBClose'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBExecSQL */
static int tolua_lua_maapi_mosync_maDBExecSQL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle databaseHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* sql = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  MAHandle tolua_ret = (MAHandle)  maDBExecSQL(databaseHandle,sql);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBExecSQL'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBExecSQLParams */
static int tolua_lua_maapi_mosync_maDBExecSQLParams00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle databaseHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* sql = ((const char*)  tolua_tostring(tolua_S,2,0));
  const void* params = ((const void*)  tolua_touserdata(tolua_S,3,0));
  int paramCount = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  MAHandle tolua_ret = (MAHandle)  maDBExecSQLParams(databaseHandle,sql,params,paramCount);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBExecSQLParams'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBCursorDestroy */
static int tolua_lua_maapi_mosync_maDBCursorDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle cursorHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maDBCursorDestroy(cursorHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBCursorDestroy'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBCursorNext */
static int tolua_lua_maapi_mosync_maDBCursorNext00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle cursorHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maDBCursorNext(cursorHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBCursorNext'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBCursorGetColumnData */
static int tolua_lua_maapi_mosync_maDBCursorGetColumnData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle cursorHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int columnIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  MAHandle placeholder = ((MAHandle)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maDBCursorGetColumnData(cursorHandle,columnIndex,placeholder);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBCursorGetColumnData'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBCursorGetColumnText */
static int tolua_lua_maapi_mosync_maDBCursorGetColumnText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle cursorHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int columnIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  void* buffer = ((void*)  tolua_touserdata(tolua_S,3,0));
  int bufferSize = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maDBCursorGetColumnText(cursorHandle,columnIndex,buffer,bufferSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBCursorGetColumnText'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBCursorGetColumnInt */
static int tolua_lua_maapi_mosync_maDBCursorGetColumnInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle cursorHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int columnIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  int value = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maDBCursorGetColumnInt(cursorHandle,columnIndex,&value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)value);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBCursorGetColumnInt'.",&tolua_err);
 return 0;
#endif
}

/* function: maDBCursorGetColumnDouble */
static int tolua_lua_maapi_mosync_maDBCursorGetColumnDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle cursorHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int columnIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  double value = ((double)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maDBCursorGetColumnDouble(cursorHandle,columnIndex,&value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 tolua_pushnumber(tolua_S,(lua_Number)value);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maDBCursorGetColumnDouble'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioDataCreateFromResource */
static int tolua_lua_maapi_mosync_maAudioDataCreateFromResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* mime = ((const char*)  tolua_tostring(tolua_S,1,0));
  MAHandle data = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
  int length = ((int)  tolua_tonumber(tolua_S,4,0));
  int flags = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  MAAudioData tolua_ret = (MAAudioData)  maAudioDataCreateFromResource(mime,data,offset,length,flags);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioDataCreateFromResource'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioDataCreateFromURL */
static int tolua_lua_maapi_mosync_maAudioDataCreateFromURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* mime = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  int flags = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  MAAudioData tolua_ret = (MAAudioData)  maAudioDataCreateFromURL(mime,url,flags);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioDataCreateFromURL'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioDataDestroy */
static int tolua_lua_maapi_mosync_maAudioDataDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioData audioData = ((MAAudioData)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAudioDataDestroy(audioData);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioDataDestroy'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioInstanceCreate */
static int tolua_lua_maapi_mosync_maAudioInstanceCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioData audioData = ((MAAudioData)  tolua_tonumber(tolua_S,1,0));
 {
  MAAudioInstance tolua_ret = (MAAudioInstance)  maAudioInstanceCreate(audioData);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioInstanceCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioInstanceCreateDynamic */
static int tolua_lua_maapi_mosync_maAudioInstanceCreateDynamic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int sampleRate = ((int)  tolua_tonumber(tolua_S,1,0));
  int numChannels = ((int)  tolua_tonumber(tolua_S,2,0));
  int bufferSize = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  MAAudioInstance tolua_ret = (MAAudioInstance)  maAudioInstanceCreateDynamic(sampleRate,numChannels,bufferSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioInstanceCreateDynamic'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioSubmitBuffer */
static int tolua_lua_maapi_mosync_maAudioSubmitBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance instance = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
  const void* buffer = ((const void*)  tolua_touserdata(tolua_S,2,0));
  int numBytes = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maAudioSubmitBuffer(instance,buffer,numBytes);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioSubmitBuffer'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioGetPendingBufferCount */
static int tolua_lua_maapi_mosync_maAudioGetPendingBufferCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance instance = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAudioGetPendingBufferCount(instance);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioGetPendingBufferCount'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioInstanceDestroy */
static int tolua_lua_maapi_mosync_maAudioInstanceDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audioInstance = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAudioInstanceDestroy(audioInstance);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioInstanceDestroy'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioGetLength */
static int tolua_lua_maapi_mosync_maAudioGetLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAudioGetLength(audio);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioGetLength'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioSetNumberOfLoops */
static int tolua_lua_maapi_mosync_maAudioSetNumberOfLoops00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
  int loops = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maAudioSetNumberOfLoops(audio,loops);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioSetNumberOfLoops'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioPrepare */
static int tolua_lua_maapi_mosync_maAudioPrepare00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
  int async = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maAudioPrepare(audio,async);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioPrepare'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioPlay */
static int tolua_lua_maapi_mosync_maAudioPlay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAudioPlay(audio);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioPlay'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioSetPosition */
static int tolua_lua_maapi_mosync_maAudioSetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
  int milliseconds = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maAudioSetPosition(audio,milliseconds);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioSetPosition'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioGetPosition */
static int tolua_lua_maapi_mosync_maAudioGetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAudioGetPosition(audio);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioGetPosition'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioSetVolume */
static int tolua_lua_maapi_mosync_maAudioSetVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
  float volume = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maAudioSetVolume(audio,volume);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioSetVolume'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioPause */
static int tolua_lua_maapi_mosync_maAudioPause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAudioPause(audio);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioPause'.",&tolua_err);
 return 0;
#endif
}

/* function: maAudioStop */
static int tolua_lua_maapi_mosync_maAudioStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAAudioInstance audio = ((MAAudioInstance)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAudioStop(audio);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAudioStop'.",&tolua_err);
 return 0;
#endif
}

/* function: maSyscallPanicsEnable */
static int tolua_lua_maapi_mosync_maSyscallPanicsEnable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maSyscallPanicsEnable();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSyscallPanicsEnable'.",&tolua_err);
 return 0;
#endif
}

/* function: maSyscallPanicsDisable */
static int tolua_lua_maapi_mosync_maSyscallPanicsDisable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maSyscallPanicsDisable();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maSyscallPanicsDisable'.",&tolua_err);
 return 0;
#endif
}

/* function: maAdsBannerCreate */
static int tolua_lua_maapi_mosync_maAdsBannerCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int bannerSize = ((int)  tolua_tonumber(tolua_S,1,0));
  const char* publisherID = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  int tolua_ret = (int)  maAdsBannerCreate(bannerSize,publisherID);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAdsBannerCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: maAdsBannerDestroy */
static int tolua_lua_maapi_mosync_maAdsBannerDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle bannerHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maAdsBannerDestroy(bannerHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAdsBannerDestroy'.",&tolua_err);
 return 0;
#endif
}

/* function: maAdsAddBannerToLayout */
static int tolua_lua_maapi_mosync_maAdsAddBannerToLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle bannerHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle layoutHandle = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maAdsAddBannerToLayout(bannerHandle,layoutHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAdsAddBannerToLayout'.",&tolua_err);
 return 0;
#endif
}

/* function: maAdsRemoveBannerFromLayout */
static int tolua_lua_maapi_mosync_maAdsRemoveBannerFromLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle bannerHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  MAHandle layoutHandle = ((MAHandle)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maAdsRemoveBannerFromLayout(bannerHandle,layoutHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAdsRemoveBannerFromLayout'.",&tolua_err);
 return 0;
#endif
}

/* function: maAdsBannerSetProperty */
static int tolua_lua_maapi_mosync_maAdsBannerSetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle bannerHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  int tolua_ret = (int)  maAdsBannerSetProperty(bannerHandle,property,value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAdsBannerSetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maAdsBannerGetProperty */
static int tolua_lua_maapi_mosync_maAdsBannerGetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle bannerHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  void* value = ((void*)  tolua_touserdata(tolua_S,3,0));
  int bufSize = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maAdsBannerGetProperty(bannerHandle,property,value,bufSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maAdsBannerGetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationLocalCreate */
static int tolua_lua_maapi_mosync_maNotificationLocalCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  MAHandle tolua_ret = (MAHandle)  maNotificationLocalCreate();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationLocalCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationLocalDestroy */
static int tolua_lua_maapi_mosync_maNotificationLocalDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle notificationHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNotificationLocalDestroy(notificationHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationLocalDestroy'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationLocalSetProperty */
static int tolua_lua_maapi_mosync_maNotificationLocalSetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle notificationHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  int tolua_ret = (int)  maNotificationLocalSetProperty(notificationHandle,property,value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationLocalSetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationLocalGetProperty */
static int tolua_lua_maapi_mosync_maNotificationLocalGetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle notificationHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  void* value = ((void*)  tolua_touserdata(tolua_S,3,0));
  int bufSize = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maNotificationLocalGetProperty(notificationHandle,property,value,bufSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationLocalGetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationLocalSchedule */
static int tolua_lua_maapi_mosync_maNotificationLocalSchedule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle notificationHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNotificationLocalSchedule(notificationHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationLocalSchedule'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationLocalUnschedule */
static int tolua_lua_maapi_mosync_maNotificationLocalUnschedule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle notificationHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNotificationLocalUnschedule(notificationHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationLocalUnschedule'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationPushRegister */
static int tolua_lua_maapi_mosync_maNotificationPushRegister00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle pushNotificationTypes = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* senderId = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  int tolua_ret = (int)  maNotificationPushRegister(pushNotificationTypes,senderId);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationPushRegister'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationPushUnregister */
static int tolua_lua_maapi_mosync_maNotificationPushUnregister00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maNotificationPushUnregister();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationPushUnregister'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationPushGetRegistration */
static int tolua_lua_maapi_mosync_maNotificationPushGetRegistration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* registrationMesssage = ((void*)  tolua_touserdata(tolua_S,1,0));
  int registrationMessageSize = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maNotificationPushGetRegistration(registrationMesssage,registrationMessageSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationPushGetRegistration'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationPushGetData */
static int tolua_lua_maapi_mosync_maNotificationPushGetData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle pushNotificationHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* pushNotificationData = ((void*)  tolua_touserdata(tolua_S,2,0));
 {
  int tolua_ret = (int)  maNotificationPushGetData(pushNotificationHandle,pushNotificationData);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationPushGetData'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationPushDestroy */
static int tolua_lua_maapi_mosync_maNotificationPushDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle notificationHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNotificationPushDestroy(notificationHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationPushDestroy'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationSetIconBadge */
static int tolua_lua_maapi_mosync_maNotificationSetIconBadge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int applicationIconBadgeNumber = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  maNotificationSetIconBadge(applicationIconBadgeNumber);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationSetIconBadge'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationGetIconBadge */
static int tolua_lua_maapi_mosync_maNotificationGetIconBadge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maNotificationGetIconBadge();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationGetIconBadge'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationPushSetTickerText */
static int tolua_lua_maapi_mosync_maNotificationPushSetTickerText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* tickerText = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNotificationPushSetTickerText(tickerText);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationPushSetTickerText'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationPushSetMessageTitle */
static int tolua_lua_maapi_mosync_maNotificationPushSetMessageTitle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* messageTitle = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNotificationPushSetMessageTitle(messageTitle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationPushSetMessageTitle'.",&tolua_err);
 return 0;
#endif
}

/* function: maNotificationPushSetDisplayFlag */
static int tolua_lua_maapi_mosync_maNotificationPushSetDisplayFlag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int displayFlag = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maNotificationPushSetDisplayFlag(displayFlag);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maNotificationPushSetDisplayFlag'.",&tolua_err);
 return 0;
#endif
}

/* function: maCaptureSetProperty */
static int tolua_lua_maapi_mosync_maCaptureSetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* property = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  int tolua_ret = (int)  maCaptureSetProperty(property,value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCaptureSetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maCaptureGetProperty */
static int tolua_lua_maapi_mosync_maCaptureGetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* property = ((const char*)  tolua_tostring(tolua_S,1,0));
  void* value = ((void*)  tolua_touserdata(tolua_S,2,0));
  int bufSize = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maCaptureGetProperty(property,value,bufSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCaptureGetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maCaptureAction */
static int tolua_lua_maapi_mosync_maCaptureAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int action = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maCaptureAction(action);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCaptureAction'.",&tolua_err);
 return 0;
#endif
}

/* function: maCaptureWriteImage */
static int tolua_lua_maapi_mosync_maCaptureWriteImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle handle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* fullPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  int fullPathBufSize = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maCaptureWriteImage(handle,fullPath,fullPathBufSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCaptureWriteImage'.",&tolua_err);
 return 0;
#endif
}

/* function: maCaptureGetImagePath */
static int tolua_lua_maapi_mosync_maCaptureGetImagePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle handle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* buffer = ((void*)  tolua_touserdata(tolua_S,2,0));
  int bufferSize = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maCaptureGetImagePath(handle,buffer,bufferSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCaptureGetImagePath'.",&tolua_err);
 return 0;
#endif
}

/* function: maCaptureGetVideoPath */
static int tolua_lua_maapi_mosync_maCaptureGetVideoPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle handle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* buffer = ((void*)  tolua_touserdata(tolua_S,2,0));
  int bufferSize = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maCaptureGetVideoPath(handle,buffer,bufferSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCaptureGetVideoPath'.",&tolua_err);
 return 0;
#endif
}

/* function: maCaptureDestroyData */
static int tolua_lua_maapi_mosync_maCaptureDestroyData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle handle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maCaptureDestroyData(handle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maCaptureDestroyData'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseSupported */
static int tolua_lua_maapi_mosync_maPurchaseSupported00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maPurchaseSupported();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseSupported'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseCreate */
static int tolua_lua_maapi_mosync_maPurchaseCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle productHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* productID = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  maPurchaseCreate(productHandle,productID);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseSetPublicKey */
static int tolua_lua_maapi_mosync_maPurchaseSetPublicKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* developerPublicKey = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  int tolua_ret = (int)  maPurchaseSetPublicKey(developerPublicKey);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseSetPublicKey'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseRequest */
static int tolua_lua_maapi_mosync_maPurchaseRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle productHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int quantity = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  maPurchaseRequest(productHandle,quantity);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseRequest'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseVerifyReceipt */
static int tolua_lua_maapi_mosync_maPurchaseVerifyReceipt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle productHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  maPurchaseVerifyReceipt(productHandle);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseVerifyReceipt'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseGetField */
static int tolua_lua_maapi_mosync_maPurchaseGetField00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle productHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  void* buffer = ((void*)  tolua_touserdata(tolua_S,3,0));
  int bufferSize = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maPurchaseGetField(productHandle,property,buffer,bufferSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseGetField'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseSetStoreURL */
static int tolua_lua_maapi_mosync_maPurchaseSetStoreURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  maPurchaseSetStoreURL(url);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseSetStoreURL'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseGetName */
static int tolua_lua_maapi_mosync_maPurchaseGetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle productHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* buffer = ((void*)  tolua_touserdata(tolua_S,2,0));
  int bufferSize = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maPurchaseGetName(productHandle,buffer,bufferSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseGetName'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseRestoreTransactions */
static int tolua_lua_maapi_mosync_maPurchaseRestoreTransactions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  maPurchaseRestoreTransactions();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseRestoreTransactions'.",&tolua_err);
 return 0;
#endif
}

/* function: maPurchaseDestroy */
static int tolua_lua_maapi_mosync_maPurchaseDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle productHandle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maPurchaseDestroy(productHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maPurchaseDestroy'.",&tolua_err);
 return 0;
#endif
}

/* function: maOpenGLInitFullscreen */
static int tolua_lua_maapi_mosync_maOpenGLInitFullscreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int glApi = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maOpenGLInitFullscreen(glApi);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maOpenGLInitFullscreen'.",&tolua_err);
 return 0;
#endif
}

/* function: maOpenGLCloseFullscreen */
static int tolua_lua_maapi_mosync_maOpenGLCloseFullscreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  maOpenGLCloseFullscreen();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maOpenGLCloseFullscreen'.",&tolua_err);
 return 0;
#endif
}

/* function: maOpenGLTexImage2D */
static int tolua_lua_maapi_mosync_maOpenGLTexImage2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle image = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maOpenGLTexImage2D(image);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maOpenGLTexImage2D'.",&tolua_err);
 return 0;
#endif
}

/* function: maOpenGLTexSubImage2D */
static int tolua_lua_maapi_mosync_maOpenGLTexSubImage2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle image = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maOpenGLTexSubImage2D(image);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maOpenGLTexSubImage2D'.",&tolua_err);
 return 0;
#endif
}

/* function: glActiveTexture */
static int tolua_lua_maapi_mosync_glActiveTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum texture = ((GLenum)  tolua_tonumber(tolua_S,1,0));
 {
  glActiveTexture(texture);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glActiveTexture'.",&tolua_err);
 return 0;
#endif
}

/* function: glBindBuffer */
static int tolua_lua_maapi_mosync_glBindBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLuint buffer = ((GLuint)  tolua_tonumber(tolua_S,2,0));
 {
  glBindBuffer(target,buffer);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glBindBuffer'.",&tolua_err);
 return 0;
#endif
}

/* function: glBindTexture */
static int tolua_lua_maapi_mosync_glBindTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLuint texture = ((GLuint)  tolua_tonumber(tolua_S,2,0));
 {
  glBindTexture(target,texture);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glBindTexture'.",&tolua_err);
 return 0;
#endif
}

/* function: glBlendFunc */
static int tolua_lua_maapi_mosync_glBlendFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum sfactor = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum dfactor = ((GLenum)  tolua_tonumber(tolua_S,2,0));
 {
  glBlendFunc(sfactor,dfactor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glBlendFunc'.",&tolua_err);
 return 0;
#endif
}

/* function: glBufferData */
static int tolua_lua_maapi_mosync_glBufferData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLsizeiptr size = ((GLsizeiptr)  tolua_tonumber(tolua_S,2,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,3,0));
  GLenum usage = ((GLenum)  tolua_tonumber(tolua_S,4,0));
 {
  glBufferData(target,size,data,usage);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glBufferData'.",&tolua_err);
 return 0;
#endif
}

/* function: glBufferSubData */
static int tolua_lua_maapi_mosync_glBufferSubData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLintptr offset = ((GLintptr)  tolua_tonumber(tolua_S,2,0));
  GLsizeiptr size = ((GLsizeiptr)  tolua_tonumber(tolua_S,3,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,4,0));
 {
  glBufferSubData(target,offset,size,data);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glBufferSubData'.",&tolua_err);
 return 0;
#endif
}

/* function: glClear */
static int tolua_lua_maapi_mosync_glClear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLbitfield mask = ((GLbitfield)  tolua_tonumber(tolua_S,1,0));
 {
  glClear(mask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glClear'.",&tolua_err);
 return 0;
#endif
}

/* function: glClearColor */
static int tolua_lua_maapi_mosync_glClearColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLclampf red = ((GLclampf)  tolua_tonumber(tolua_S,1,0));
  GLclampf green = ((GLclampf)  tolua_tonumber(tolua_S,2,0));
  GLclampf blue = ((GLclampf)  tolua_tonumber(tolua_S,3,0));
  GLclampf alpha = ((GLclampf)  tolua_tonumber(tolua_S,4,0));
 {
  glClearColor(red,green,blue,alpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glClearColor'.",&tolua_err);
 return 0;
#endif
}

/* function: glClearDepthf */
static int tolua_lua_maapi_mosync_glClearDepthf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLclampf depth = ((GLclampf)  tolua_tonumber(tolua_S,1,0));
 {
  glClearDepthf(depth);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glClearDepthf'.",&tolua_err);
 return 0;
#endif
}

/* function: glClearStencil */
static int tolua_lua_maapi_mosync_glClearStencil00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLint s = ((GLint)  tolua_tonumber(tolua_S,1,0));
 {
  glClearStencil(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glClearStencil'.",&tolua_err);
 return 0;
#endif
}

/* function: glColorMask */
static int tolua_lua_maapi_mosync_glColorMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLboolean red = ((GLboolean)  tolua_tonumber(tolua_S,1,0));
  GLboolean green = ((GLboolean)  tolua_tonumber(tolua_S,2,0));
  GLboolean blue = ((GLboolean)  tolua_tonumber(tolua_S,3,0));
  GLboolean alpha = ((GLboolean)  tolua_tonumber(tolua_S,4,0));
 {
  glColorMask(red,green,blue,alpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glColorMask'.",&tolua_err);
 return 0;
#endif
}

/* function: glCompressedTexImage2D */
static int tolua_lua_maapi_mosync_glCompressedTexImage2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,8,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint level = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLenum internalformat = ((GLenum)  tolua_tonumber(tolua_S,3,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,4,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,5,0));
  GLint border = ((GLint)  tolua_tonumber(tolua_S,6,0));
  GLsizei imageSize = ((GLsizei)  tolua_tonumber(tolua_S,7,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,8,0));
 {
  glCompressedTexImage2D(target,level,internalformat,width,height,border,imageSize,data);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glCompressedTexImage2D'.",&tolua_err);
 return 0;
#endif
}

/* function: glCompressedTexSubImage2D */
static int tolua_lua_maapi_mosync_glCompressedTexSubImage2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,8,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,9,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint level = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLint xoffset = ((GLint)  tolua_tonumber(tolua_S,3,0));
  GLint yoffset = ((GLint)  tolua_tonumber(tolua_S,4,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,5,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,6,0));
  GLenum format = ((GLenum)  tolua_tonumber(tolua_S,7,0));
  GLsizei imageSize = ((GLsizei)  tolua_tonumber(tolua_S,8,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,9,0));
 {
  glCompressedTexSubImage2D(target,level,xoffset,yoffset,width,height,format,imageSize,data);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glCompressedTexSubImage2D'.",&tolua_err);
 return 0;
#endif
}

/* function: glCopyTexImage2D */
static int tolua_lua_maapi_mosync_glCopyTexImage2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,8,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint level = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLenum internalformat = ((GLenum)  tolua_tonumber(tolua_S,3,0));
  GLint x = ((GLint)  tolua_tonumber(tolua_S,4,0));
  GLint y = ((GLint)  tolua_tonumber(tolua_S,5,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,6,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,7,0));
  GLint border = ((GLint)  tolua_tonumber(tolua_S,8,0));
 {
  glCopyTexImage2D(target,level,internalformat,x,y,width,height,border);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glCopyTexImage2D'.",&tolua_err);
 return 0;
#endif
}

/* function: glCopyTexSubImage2D */
static int tolua_lua_maapi_mosync_glCopyTexSubImage2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,8,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint level = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLint xoffset = ((GLint)  tolua_tonumber(tolua_S,3,0));
  GLint yoffset = ((GLint)  tolua_tonumber(tolua_S,4,0));
  GLint x = ((GLint)  tolua_tonumber(tolua_S,5,0));
  GLint y = ((GLint)  tolua_tonumber(tolua_S,6,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,7,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,8,0));
 {
  glCopyTexSubImage2D(target,level,xoffset,yoffset,x,y,width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glCopyTexSubImage2D'.",&tolua_err);
 return 0;
#endif
}

/* function: glCullFace */
static int tolua_lua_maapi_mosync_glCullFace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum mode = ((GLenum)  tolua_tonumber(tolua_S,1,0));
 {
  glCullFace(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glCullFace'.",&tolua_err);
 return 0;
#endif
}

/* function: glDeleteBuffers */
static int tolua_lua_maapi_mosync_glDeleteBuffers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLsizei n = ((GLsizei)  tolua_tonumber(tolua_S,1,0));
  const void* buffers = ((const void*)  tolua_touserdata(tolua_S,2,0));
 {
  glDeleteBuffers(n,buffers);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glDeleteBuffers'.",&tolua_err);
 return 0;
#endif
}

/* function: glDeleteTextures */
static int tolua_lua_maapi_mosync_glDeleteTextures00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLsizei n = ((GLsizei)  tolua_tonumber(tolua_S,1,0));
  const void* textures = ((const void*)  tolua_touserdata(tolua_S,2,0));
 {
  glDeleteTextures(n,textures);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glDeleteTextures'.",&tolua_err);
 return 0;
#endif
}

/* function: glDepthFunc */
static int tolua_lua_maapi_mosync_glDepthFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum func = ((GLenum)  tolua_tonumber(tolua_S,1,0));
 {
  glDepthFunc(func);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glDepthFunc'.",&tolua_err);
 return 0;
#endif
}

/* function: glDepthMask */
static int tolua_lua_maapi_mosync_glDepthMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLboolean flag = ((GLboolean)  tolua_tonumber(tolua_S,1,0));
 {
  glDepthMask(flag);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glDepthMask'.",&tolua_err);
 return 0;
#endif
}

/* function: glDepthRangef */
static int tolua_lua_maapi_mosync_glDepthRangef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLclampf zNear = ((GLclampf)  tolua_tonumber(tolua_S,1,0));
  GLclampf zFar = ((GLclampf)  tolua_tonumber(tolua_S,2,0));
 {
  glDepthRangef(zNear,zFar);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glDepthRangef'.",&tolua_err);
 return 0;
#endif
}

/* function: glDisable */
static int tolua_lua_maapi_mosync_glDisable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum cap = ((GLenum)  tolua_tonumber(tolua_S,1,0));
 {
  glDisable(cap);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glDisable'.",&tolua_err);
 return 0;
#endif
}

/* function: glDrawArrays */
static int tolua_lua_maapi_mosync_glDrawArrays00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum mode = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint first = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLsizei count = ((GLsizei)  tolua_tonumber(tolua_S,3,0));
 {
  glDrawArrays(mode,first,count);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glDrawArrays'.",&tolua_err);
 return 0;
#endif
}

/* function: glDrawElements */
static int tolua_lua_maapi_mosync_glDrawElements00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum mode = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLsizei count = ((GLsizei)  tolua_tonumber(tolua_S,2,0));
  GLenum type = ((GLenum)  tolua_tonumber(tolua_S,3,0));
  const void* indices = ((const void*)  tolua_touserdata(tolua_S,4,0));
 {
  glDrawElements(mode,count,type,indices);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glDrawElements'.",&tolua_err);
 return 0;
#endif
}

/* function: glEnable */
static int tolua_lua_maapi_mosync_glEnable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum cap = ((GLenum)  tolua_tonumber(tolua_S,1,0));
 {
  glEnable(cap);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glEnable'.",&tolua_err);
 return 0;
#endif
}

/* function: glFinish */
static int tolua_lua_maapi_mosync_glFinish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  glFinish();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glFinish'.",&tolua_err);
 return 0;
#endif
}

/* function: glFlush */
static int tolua_lua_maapi_mosync_glFlush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  glFlush();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glFlush'.",&tolua_err);
 return 0;
#endif
}

/* function: glFrontFace */
static int tolua_lua_maapi_mosync_glFrontFace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum mode = ((GLenum)  tolua_tonumber(tolua_S,1,0));
 {
  glFrontFace(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glFrontFace'.",&tolua_err);
 return 0;
#endif
}

/* function: glGenBuffers */
static int tolua_lua_maapi_mosync_glGenBuffers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLsizei n = ((GLsizei)  tolua_tonumber(tolua_S,1,0));
  GLuint buffers = ((GLuint)  tolua_tonumber(tolua_S,2,0));
 {
  glGenBuffers(n,&buffers);
 tolua_pushnumber(tolua_S,(lua_Number)buffers);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGenBuffers'.",&tolua_err);
 return 0;
#endif
}

/* function: glGenTextures */
static int tolua_lua_maapi_mosync_glGenTextures00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLsizei n = ((GLsizei)  tolua_tonumber(tolua_S,1,0));
  GLuint textures = ((GLuint)  tolua_tonumber(tolua_S,2,0));
 {
  glGenTextures(n,&textures);
 tolua_pushnumber(tolua_S,(lua_Number)textures);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGenTextures'.",&tolua_err);
 return 0;
#endif
}

/* function: glGetBooleanv */
static int tolua_lua_maapi_mosync_glGetBooleanv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLboolean params = ((GLboolean)  tolua_tonumber(tolua_S,2,0));
 {
  glGetBooleanv(pname,&params);
 tolua_pushnumber(tolua_S,(lua_Number)params);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGetBooleanv'.",&tolua_err);
 return 0;
#endif
}

/* function: glGetBufferParameteriv */
static int tolua_lua_maapi_mosync_glGetBufferParameteriv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,2,0));
  GLint params = ((GLint)  tolua_tonumber(tolua_S,3,0));
 {
  glGetBufferParameteriv(target,pname,&params);
 tolua_pushnumber(tolua_S,(lua_Number)params);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGetBufferParameteriv'.",&tolua_err);
 return 0;
#endif
}

/* function: glGetError */
static int tolua_lua_maapi_mosync_glGetError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  GLenum tolua_ret = (GLenum)  glGetError();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGetError'.",&tolua_err);
 return 0;
#endif
}

/* function: glGetFloatv */
static int tolua_lua_maapi_mosync_glGetFloatv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLfloat params = ((GLfloat)  tolua_tonumber(tolua_S,2,0));
 {
  glGetFloatv(pname,&params);
 tolua_pushnumber(tolua_S,(lua_Number)params);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGetFloatv'.",&tolua_err);
 return 0;
#endif
}

/* function: glGetIntegerv */
static int tolua_lua_maapi_mosync_glGetIntegerv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint params = ((GLint)  tolua_tonumber(tolua_S,2,0));
 {
  glGetIntegerv(pname,&params);
 tolua_pushnumber(tolua_S,(lua_Number)params);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGetIntegerv'.",&tolua_err);
 return 0;
#endif
}

/* function: glGetStringHandle */
static int tolua_lua_maapi_mosync_glGetStringHandle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum name = ((GLenum)  tolua_tonumber(tolua_S,1,0));
 {
  MAHandle tolua_ret = (MAHandle)  glGetStringHandle(name);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGetStringHandle'.",&tolua_err);
 return 0;
#endif
}

/* function: glGetTexParameterfv */
static int tolua_lua_maapi_mosync_glGetTexParameterfv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,2,0));
  GLfloat params = ((GLfloat)  tolua_tonumber(tolua_S,3,0));
 {
  glGetTexParameterfv(target,pname,&params);
 tolua_pushnumber(tolua_S,(lua_Number)params);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGetTexParameterfv'.",&tolua_err);
 return 0;
#endif
}

/* function: glGetTexParameteriv */
static int tolua_lua_maapi_mosync_glGetTexParameteriv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,2,0));
  GLint params = ((GLint)  tolua_tonumber(tolua_S,3,0));
 {
  glGetTexParameteriv(target,pname,&params);
 tolua_pushnumber(tolua_S,(lua_Number)params);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glGetTexParameteriv'.",&tolua_err);
 return 0;
#endif
}

/* function: glHint */
static int tolua_lua_maapi_mosync_glHint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum mode = ((GLenum)  tolua_tonumber(tolua_S,2,0));
 {
  glHint(target,mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glHint'.",&tolua_err);
 return 0;
#endif
}

/* function: glIsBuffer */
static int tolua_lua_maapi_mosync_glIsBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLuint buffer = ((GLuint)  tolua_tonumber(tolua_S,1,0));
 {
  GLboolean tolua_ret = (GLboolean)  glIsBuffer(buffer);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glIsBuffer'.",&tolua_err);
 return 0;
#endif
}

/* function: glIsEnabled */
static int tolua_lua_maapi_mosync_glIsEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum cap = ((GLenum)  tolua_tonumber(tolua_S,1,0));
 {
  GLboolean tolua_ret = (GLboolean)  glIsEnabled(cap);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glIsEnabled'.",&tolua_err);
 return 0;
#endif
}

/* function: glIsTexture */
static int tolua_lua_maapi_mosync_glIsTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLuint texture = ((GLuint)  tolua_tonumber(tolua_S,1,0));
 {
  GLboolean tolua_ret = (GLboolean)  glIsTexture(texture);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glIsTexture'.",&tolua_err);
 return 0;
#endif
}

/* function: glLineWidth */
static int tolua_lua_maapi_mosync_glLineWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLfloat width = ((GLfloat)  tolua_tonumber(tolua_S,1,0));
 {
  glLineWidth(width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glLineWidth'.",&tolua_err);
 return 0;
#endif
}

/* function: glPixelStorei */
static int tolua_lua_maapi_mosync_glPixelStorei00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint param = ((GLint)  tolua_tonumber(tolua_S,2,0));
 {
  glPixelStorei(pname,param);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glPixelStorei'.",&tolua_err);
 return 0;
#endif
}

/* function: glPolygonOffset */
static int tolua_lua_maapi_mosync_glPolygonOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLfloat factor = ((GLfloat)  tolua_tonumber(tolua_S,1,0));
  GLfloat units = ((GLfloat)  tolua_tonumber(tolua_S,2,0));
 {
  glPolygonOffset(factor,units);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glPolygonOffset'.",&tolua_err);
 return 0;
#endif
}

/* function: glReadPixels */
static int tolua_lua_maapi_mosync_glReadPixels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,7,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLint x = ((GLint)  tolua_tonumber(tolua_S,1,0));
  GLint y = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,3,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,4,0));
  GLenum format = ((GLenum)  tolua_tonumber(tolua_S,5,0));
  GLenum type = ((GLenum)  tolua_tonumber(tolua_S,6,0));
  void* pixels = ((void*)  tolua_touserdata(tolua_S,7,0));
 {
  glReadPixels(x,y,width,height,format,type,pixels);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glReadPixels'.",&tolua_err);
 return 0;
#endif
}

/* function: glSampleCoverage */
static int tolua_lua_maapi_mosync_glSampleCoverage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLclampf value = ((GLclampf)  tolua_tonumber(tolua_S,1,0));
  GLboolean invert = ((GLboolean)  tolua_tonumber(tolua_S,2,0));
 {
  glSampleCoverage(value,invert);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glSampleCoverage'.",&tolua_err);
 return 0;
#endif
}

/* function: glScissor */
static int tolua_lua_maapi_mosync_glScissor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLint x = ((GLint)  tolua_tonumber(tolua_S,1,0));
  GLint y = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,3,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,4,0));
 {
  glScissor(x,y,width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glScissor'.",&tolua_err);
 return 0;
#endif
}

/* function: glStencilFunc */
static int tolua_lua_maapi_mosync_glStencilFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum func = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint ref = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLuint mask = ((GLuint)  tolua_tonumber(tolua_S,3,0));
 {
  glStencilFunc(func,ref,mask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glStencilFunc'.",&tolua_err);
 return 0;
#endif
}

/* function: glStencilMask */
static int tolua_lua_maapi_mosync_glStencilMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLuint mask = ((GLuint)  tolua_tonumber(tolua_S,1,0));
 {
  glStencilMask(mask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glStencilMask'.",&tolua_err);
 return 0;
#endif
}

/* function: glStencilOp */
static int tolua_lua_maapi_mosync_glStencilOp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum fail = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum zfail = ((GLenum)  tolua_tonumber(tolua_S,2,0));
  GLenum zpass = ((GLenum)  tolua_tonumber(tolua_S,3,0));
 {
  glStencilOp(fail,zfail,zpass);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glStencilOp'.",&tolua_err);
 return 0;
#endif
}

/* function: glTexImage2D */
static int tolua_lua_maapi_mosync_glTexImage2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,8,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,9,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint level = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLint internalformat = ((GLint)  tolua_tonumber(tolua_S,3,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,4,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,5,0));
  GLint border = ((GLint)  tolua_tonumber(tolua_S,6,0));
  GLenum format = ((GLenum)  tolua_tonumber(tolua_S,7,0));
  GLenum type = ((GLenum)  tolua_tonumber(tolua_S,8,0));
  const void* pixels = ((const void*)  tolua_touserdata(tolua_S,9,0));
 {
  glTexImage2D(target,level,internalformat,width,height,border,format,type,pixels);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glTexImage2D'.",&tolua_err);
 return 0;
#endif
}

/* function: glTexParameterf */
static int tolua_lua_maapi_mosync_glTexParameterf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,2,0));
  GLfloat param = ((GLfloat)  tolua_tonumber(tolua_S,3,0));
 {
  glTexParameterf(target,pname,param);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glTexParameterf'.",&tolua_err);
 return 0;
#endif
}

/* function: glTexParameterfv */
static int tolua_lua_maapi_mosync_glTexParameterfv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,2,0));
  const void* params = ((const void*)  tolua_touserdata(tolua_S,3,0));
 {
  glTexParameterfv(target,pname,params);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glTexParameterfv'.",&tolua_err);
 return 0;
#endif
}

/* function: glTexParameteri */
static int tolua_lua_maapi_mosync_glTexParameteri00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,2,0));
  GLint param = ((GLint)  tolua_tonumber(tolua_S,3,0));
 {
  glTexParameteri(target,pname,param);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glTexParameteri'.",&tolua_err);
 return 0;
#endif
}

/* function: glTexParameteriv */
static int tolua_lua_maapi_mosync_glTexParameteriv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLenum pname = ((GLenum)  tolua_tonumber(tolua_S,2,0));
  const void* params = ((const void*)  tolua_touserdata(tolua_S,3,0));
 {
  glTexParameteriv(target,pname,params);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glTexParameteriv'.",&tolua_err);
 return 0;
#endif
}

/* function: glTexSubImage2D */
static int tolua_lua_maapi_mosync_glTexSubImage2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,8,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,9,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLenum target = ((GLenum)  tolua_tonumber(tolua_S,1,0));
  GLint level = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLint xoffset = ((GLint)  tolua_tonumber(tolua_S,3,0));
  GLint yoffset = ((GLint)  tolua_tonumber(tolua_S,4,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,5,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,6,0));
  GLenum format = ((GLenum)  tolua_tonumber(tolua_S,7,0));
  GLenum type = ((GLenum)  tolua_tonumber(tolua_S,8,0));
  const void* pixels = ((const void*)  tolua_touserdata(tolua_S,9,0));
 {
  glTexSubImage2D(target,level,xoffset,yoffset,width,height,format,type,pixels);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glTexSubImage2D'.",&tolua_err);
 return 0;
#endif
}

/* function: glViewport */
static int tolua_lua_maapi_mosync_glViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  GLint x = ((GLint)  tolua_tonumber(tolua_S,1,0));
  GLint y = ((GLint)  tolua_tonumber(tolua_S,2,0));
  GLsizei width = ((GLsizei)  tolua_tonumber(tolua_S,3,0));
  GLsizei height = ((GLsizei)  tolua_tonumber(tolua_S,4,0));
 {
  glViewport(x,y,width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'glViewport'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetCreate */
static int tolua_lua_maapi_mosync_maWidgetCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* widgetType = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  MAWidgetHandle tolua_ret = (MAWidgetHandle)  maWidgetCreate(widgetType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetDestroy */
static int tolua_lua_maapi_mosync_maWidgetDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle widget = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maWidgetDestroy(widget);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetDestroy'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetAddChild */
static int tolua_lua_maapi_mosync_maWidgetAddChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle parent = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
  MAWidgetHandle child = ((MAWidgetHandle)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maWidgetAddChild(parent,child);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetAddChild'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetInsertChild */
static int tolua_lua_maapi_mosync_maWidgetInsertChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle parent = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
  MAWidgetHandle child = ((MAWidgetHandle)  tolua_tonumber(tolua_S,2,0));
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  int tolua_ret = (int)  maWidgetInsertChild(parent,child,index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetInsertChild'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetRemoveChild */
static int tolua_lua_maapi_mosync_maWidgetRemoveChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle child = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maWidgetRemoveChild(child);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetRemoveChild'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetModalDialogShow */
static int tolua_lua_maapi_mosync_maWidgetModalDialogShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle dialogHandle = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maWidgetModalDialogShow(dialogHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetModalDialogShow'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetModalDialogHide */
static int tolua_lua_maapi_mosync_maWidgetModalDialogHide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle dialogHandle = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maWidgetModalDialogHide(dialogHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetModalDialogHide'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetScreenShow */
static int tolua_lua_maapi_mosync_maWidgetScreenShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle screenHandle = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maWidgetScreenShow(screenHandle);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetScreenShow'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetStackScreenPush */
static int tolua_lua_maapi_mosync_maWidgetStackScreenPush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle stackScreen = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
  MAWidgetHandle newScreen = ((MAWidgetHandle)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  maWidgetStackScreenPush(stackScreen,newScreen);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetStackScreenPush'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetStackScreenPop */
static int tolua_lua_maapi_mosync_maWidgetStackScreenPop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle stackScreen = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  maWidgetStackScreenPop(stackScreen);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetStackScreenPop'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetSetProperty */
static int tolua_lua_maapi_mosync_maWidgetSetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle widget = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  int tolua_ret = (int)  maWidgetSetProperty(widget,property,value);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetSetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetGetProperty */
static int tolua_lua_maapi_mosync_maWidgetGetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle widget = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
  const char* property = ((const char*)  tolua_tostring(tolua_S,2,0));
  void* value = ((void*)  tolua_touserdata(tolua_S,3,0));
  int bufSize = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maWidgetGetProperty(widget,property,value,bufSize);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetGetProperty'.",&tolua_err);
 return 0;
#endif
}

/* function: maWidgetScreenAddOptionsMenuItem */
static int tolua_lua_maapi_mosync_maWidgetScreenAddOptionsMenuItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAWidgetHandle widget = ((MAWidgetHandle)  tolua_tonumber(tolua_S,1,0));
  const char* title = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* iconPath = ((const char*)  tolua_tostring(tolua_S,3,0));
  int iconPredefined = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  int tolua_ret = (int)  maWidgetScreenAddOptionsMenuItem(widget,title,iconPath,iconPredefined);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maWidgetScreenAddOptionsMenuItem'.",&tolua_err);
 return 0;
#endif
}

/* function: EXTENT */
static int tolua_lua_maapi_mosync_EXTENT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  MAExtent tolua_ret = (MAExtent)  EXTENT(x,y);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EXTENT'.",&tolua_err);
 return 0;
#endif
}

/* function: EXTENT_X */
static int tolua_lua_maapi_mosync_EXTENT_X00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAExtent extent = ((MAExtent)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  EXTENT_X(extent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EXTENT_X'.",&tolua_err);
 return 0;
#endif
}

/* function: EXTENT_Y */
static int tolua_lua_maapi_mosync_EXTENT_Y00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAExtent extent = ((MAExtent)  tolua_tonumber(tolua_S,1,0));
 {
  int tolua_ret = (int)  EXTENT_Y(extent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EXTENT_Y'.",&tolua_err);
 return 0;
#endif
}

/* function: SysImageScale */
static int tolua_lua_maapi_mosync_SysImageScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle sourceImage = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* sourceRect = ((void*)  tolua_touserdata(tolua_S,2,0));
  MAHandle destImagePlaceholder = ((MAHandle)  tolua_tonumber(tolua_S,3,0));
  int scaledImageWidth = ((int)  tolua_tonumber(tolua_S,4,0));
  int scaledImageHeight = ((int)  tolua_tonumber(tolua_S,5,0));
  int scaleType = ((int)  tolua_tonumber(tolua_S,6,0));
 {
  int tolua_ret = (int)  SysImageScale(sourceImage,sourceRect,destImagePlaceholder,scaledImageWidth,scaledImageHeight,scaleType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysImageScale'.",&tolua_err);
 return 0;
#endif
}

/* function: SysImageScaleProportionally */
static int tolua_lua_maapi_mosync_SysImageScaleProportionally00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle sourceImage = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  void* sourceRect = ((void*)  tolua_touserdata(tolua_S,2,0));
  MAHandle destImagePlaceholder = ((MAHandle)  tolua_tonumber(tolua_S,3,0));
  double scaleFactor = ((double)  tolua_tonumber(tolua_S,4,0));
  int scaleType = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  int tolua_ret = (int)  SysImageScaleProportionally(sourceImage,sourceRect,destImagePlaceholder,scaleFactor,scaleType);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysImageScaleProportionally'.",&tolua_err);
 return 0;
#endif
}

/* function: SysTextCreate */
static int tolua_lua_maapi_mosync_SysTextCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int fontHandle = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  void* tolua_ret = (void*)  SysTextCreate(fontHandle);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysTextCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: SysTextDelete */
static int tolua_lua_maapi_mosync_SysTextDelete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* textObj = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  SysTextDelete(textObj);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysTextDelete'.",&tolua_err);
 return 0;
#endif
}

/* function: SysTextSetString */
static int tolua_lua_maapi_mosync_SysTextSetString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* textObj = ((void*)  tolua_touserdata(tolua_S,1,0));
  void* str = ((void*)  tolua_touserdata(tolua_S,2,0));
 {
  SysTextSetString(textObj,str);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysTextSetString'.",&tolua_err);
 return 0;
#endif
}

/* function: SysTextSetLineSpacing */
static int tolua_lua_maapi_mosync_SysTextSetLineSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* textObj = ((void*)  tolua_touserdata(tolua_S,1,0));
  int lineSpacing = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SysTextSetLineSpacing(textObj,lineSpacing);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysTextSetLineSpacing'.",&tolua_err);
 return 0;
#endif
}

/* function: SysTextGetStringSize */
static int tolua_lua_maapi_mosync_SysTextGetStringSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* textObj = ((void*)  tolua_touserdata(tolua_S,1,0));
  int extent = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  SysTextGetStringSize(textObj,extent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysTextGetStringSize'.",&tolua_err);
 return 0;
#endif
}

/* function: SysTextDrawString */
static int tolua_lua_maapi_mosync_SysTextDrawString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* textObj = ((void*)  tolua_touserdata(tolua_S,1,0));
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int extent = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  SysTextDrawString(textObj,x,y,extent);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysTextDrawString'.",&tolua_err);
 return 0;
#endif
}

/* function: SysAlloc */
static int tolua_lua_maapi_mosync_SysAlloc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int size = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  void* tolua_ret = (void*)  SysAlloc(size);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysAlloc'.",&tolua_err);
 return 0;
#endif
}

/* function: SysFree */
static int tolua_lua_maapi_mosync_SysFree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* buffer = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  SysFree(buffer);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysFree'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBufferGetInt */
static int tolua_lua_maapi_mosync_SysBufferGetInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* buffer = ((void*)  tolua_touserdata(tolua_S,1,0));
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  SysBufferGetInt(buffer,index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBufferGetInt'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBufferSetInt */
static int tolua_lua_maapi_mosync_SysBufferSetInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* buffer = ((void*)  tolua_touserdata(tolua_S,1,0));
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  int value = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  SysBufferSetInt(buffer,index,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBufferSetInt'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBufferGetByte */
static int tolua_lua_maapi_mosync_SysBufferGetByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* buffer = ((void*)  tolua_touserdata(tolua_S,1,0));
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  SysBufferGetByte(buffer,index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBufferGetByte'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBufferSetByte */
static int tolua_lua_maapi_mosync_SysBufferSetByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* buffer = ((void*)  tolua_touserdata(tolua_S,1,0));
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  int value = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  SysBufferSetByte(buffer,index,value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBufferSetByte'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBufferGetFloat */
static int tolua_lua_maapi_mosync_SysBufferGetFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* buffer = ((void*)  tolua_touserdata(tolua_S,1,0));
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  float tolua_ret = (float)  SysBufferGetFloat(buffer,index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBufferGetFloat'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBufferGetDouble */
static int tolua_lua_maapi_mosync_SysBufferGetDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* buffer = ((void*)  tolua_touserdata(tolua_S,1,0));
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  double tolua_ret = (double)  SysBufferGetDouble(buffer,index);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBufferGetDouble'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBufferCopyBytes */
static int tolua_lua_maapi_mosync_SysBufferCopyBytes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* sourceBuffer = ((void*)  tolua_touserdata(tolua_S,1,0));
  int sourceIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  void* destBuffer = ((void*)  tolua_touserdata(tolua_S,3,0));
  int destIndex = ((int)  tolua_tonumber(tolua_S,4,0));
  int numberOfBytesToCopy = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  SysBufferCopyBytes(sourceBuffer,sourceIndex,destBuffer,destIndex,numberOfBytesToCopy);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBufferCopyBytes'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBufferGetBytePointer */
static int tolua_lua_maapi_mosync_SysBufferGetBytePointer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* buffer = ((void*)  tolua_touserdata(tolua_S,1,0));
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  void* tolua_ret = (void*)  SysBufferGetBytePointer(buffer,index);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBufferGetBytePointer'.",&tolua_err);
 return 0;
#endif
}

/* function: SysSizeOfInt */
static int tolua_lua_maapi_mosync_SysSizeOfInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  SysSizeOfInt();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysSizeOfInt'.",&tolua_err);
 return 0;
#endif
}

/* function: SysSizeOfFloat */
static int tolua_lua_maapi_mosync_SysSizeOfFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  SysSizeOfFloat();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysSizeOfFloat'.",&tolua_err);
 return 0;
#endif
}

/* function: SysSizeOfDouble */
static int tolua_lua_maapi_mosync_SysSizeOfDouble00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  int tolua_ret = (int)  SysSizeOfDouble();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysSizeOfDouble'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBitAnd */
static int tolua_lua_maapi_mosync_SysBitAnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
  int b = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  SysBitAnd(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBitAnd'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBitOr */
static int tolua_lua_maapi_mosync_SysBitOr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
  int b = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  SysBitOr(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBitOr'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBitXor */
static int tolua_lua_maapi_mosync_SysBitXor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
  int b = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  SysBitXor(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBitXor'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBitShiftLeft */
static int tolua_lua_maapi_mosync_SysBitShiftLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
  int bits = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  SysBitShiftLeft(a,bits);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBitShiftLeft'.",&tolua_err);
 return 0;
#endif
}

/* function: SysBitShiftRight */
static int tolua_lua_maapi_mosync_SysBitShiftRight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
  int bits = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  SysBitShiftRight(a,bits);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysBitShiftRight'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventCreate */
static int tolua_lua_maapi_mosync_SysEventCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  void* tolua_ret = (void*)  SysEventCreate();
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetType */
static int tolua_lua_maapi_mosync_SysEventGetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetType(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetType'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetKey */
static int tolua_lua_maapi_mosync_SysEventGetKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetKey(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetKey'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetNativeKey */
static int tolua_lua_maapi_mosync_SysEventGetNativeKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetNativeKey(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetNativeKey'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetCharacter */
static int tolua_lua_maapi_mosync_SysEventGetCharacter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  uint tolua_ret = (uint)  SysEventGetCharacter(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetCharacter'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetX */
static int tolua_lua_maapi_mosync_SysEventGetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetX(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetX'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetY */
static int tolua_lua_maapi_mosync_SysEventGetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetY(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetY'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetTouchId */
static int tolua_lua_maapi_mosync_SysEventGetTouchId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetTouchId(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetTouchId'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetState */
static int tolua_lua_maapi_mosync_SysEventGetState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetState(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetState'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetConnHandle */
static int tolua_lua_maapi_mosync_SysEventGetConnHandle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  MAHandle tolua_ret = (MAHandle)  SysEventGetConnHandle(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetConnHandle'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetConnOpType */
static int tolua_lua_maapi_mosync_SysEventGetConnOpType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetConnOpType(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetConnOpType'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetConnResult */
static int tolua_lua_maapi_mosync_SysEventGetConnResult00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetConnResult(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetConnResult'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetTextBoxResult */
static int tolua_lua_maapi_mosync_SysEventGetTextBoxResult00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetTextBoxResult(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetTextBoxResult'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetTextBoxLength */
static int tolua_lua_maapi_mosync_SysEventGetTextBoxLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventGetTextBoxLength(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetTextBoxLength'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventGetData */
static int tolua_lua_maapi_mosync_SysEventGetData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  void* tolua_ret = (void*)  SysEventGetData(event);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventGetData'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventSensorGetType */
static int tolua_lua_maapi_mosync_SysEventSensorGetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventSensorGetType(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventSensorGetType'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventSensorGetValue1 */
static int tolua_lua_maapi_mosync_SysEventSensorGetValue100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  float tolua_ret = (float)  SysEventSensorGetValue1(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventSensorGetValue1'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventSensorGetValue2 */
static int tolua_lua_maapi_mosync_SysEventSensorGetValue200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  float tolua_ret = (float)  SysEventSensorGetValue2(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventSensorGetValue2'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventSensorGetValue3 */
static int tolua_lua_maapi_mosync_SysEventSensorGetValue300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  float tolua_ret = (float)  SysEventSensorGetValue3(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventSensorGetValue3'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventLocationGetState */
static int tolua_lua_maapi_mosync_SysEventLocationGetState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysEventLocationGetState(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventLocationGetState'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventLocationGetLat */
static int tolua_lua_maapi_mosync_SysEventLocationGetLat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  double tolua_ret = (double)  SysEventLocationGetLat(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventLocationGetLat'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventLocationGetLon */
static int tolua_lua_maapi_mosync_SysEventLocationGetLon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  double tolua_ret = (double)  SysEventLocationGetLon(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventLocationGetLon'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventLocationGetHorzAcc */
static int tolua_lua_maapi_mosync_SysEventLocationGetHorzAcc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  double tolua_ret = (double)  SysEventLocationGetHorzAcc(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventLocationGetHorzAcc'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventLocationGetVertAcc */
static int tolua_lua_maapi_mosync_SysEventLocationGetVertAcc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  double tolua_ret = (double)  SysEventLocationGetVertAcc(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventLocationGetVertAcc'.",&tolua_err);
 return 0;
#endif
}

/* function: SysEventLocationGetAlt */
static int tolua_lua_maapi_mosync_SysEventLocationGetAlt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* event = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  float tolua_ret = (float)  SysEventLocationGetAlt(event);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysEventLocationGetAlt'.",&tolua_err);
 return 0;
#endif
}

/* function: SysWidgetEventGetType */
static int tolua_lua_maapi_mosync_SysWidgetEventGetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* widgetEvent = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysWidgetEventGetType(widgetEvent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysWidgetEventGetType'.",&tolua_err);
 return 0;
#endif
}

/* function: SysWidgetEventGetHandle */
static int tolua_lua_maapi_mosync_SysWidgetEventGetHandle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* widgetEvent = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysWidgetEventGetHandle(widgetEvent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysWidgetEventGetHandle'.",&tolua_err);
 return 0;
#endif
}

/* function: SysWidgetEventGetListItemIndex */
static int tolua_lua_maapi_mosync_SysWidgetEventGetListItemIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* widgetEvent = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysWidgetEventGetListItemIndex(widgetEvent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysWidgetEventGetListItemIndex'.",&tolua_err);
 return 0;
#endif
}

/* function: SysWidgetEventGetChecked */
static int tolua_lua_maapi_mosync_SysWidgetEventGetChecked00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* widgetEvent = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysWidgetEventGetChecked(widgetEvent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysWidgetEventGetChecked'.",&tolua_err);
 return 0;
#endif
}

/* function: SysWidgetEventGetTabIndex */
static int tolua_lua_maapi_mosync_SysWidgetEventGetTabIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* widgetEvent = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysWidgetEventGetTabIndex(widgetEvent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysWidgetEventGetTabIndex'.",&tolua_err);
 return 0;
#endif
}

/* function: SysWidgetEventGetUrlData */
static int tolua_lua_maapi_mosync_SysWidgetEventGetUrlData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* widgetEvent = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysWidgetEventGetUrlData(widgetEvent);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysWidgetEventGetUrlData'.",&tolua_err);
 return 0;
#endif
}

/* function: SysPointCreate */
static int tolua_lua_maapi_mosync_SysPointCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  void* tolua_ret = (void*)  SysPointCreate();
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysPointCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: SysPointGetX */
static int tolua_lua_maapi_mosync_SysPointGetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* point = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysPointGetX(point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysPointGetX'.",&tolua_err);
 return 0;
#endif
}

/* function: SysPointGetY */
static int tolua_lua_maapi_mosync_SysPointGetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* point = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysPointGetY(point);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysPointGetY'.",&tolua_err);
 return 0;
#endif
}

/* function: SysPointSetX */
static int tolua_lua_maapi_mosync_SysPointSetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* point = ((void*)  tolua_touserdata(tolua_S,1,0));
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SysPointSetX(point,x);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysPointSetX'.",&tolua_err);
 return 0;
#endif
}

/* function: SysPointSetY */
static int tolua_lua_maapi_mosync_SysPointSetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* point = ((void*)  tolua_touserdata(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SysPointSetY(point,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysPointSetY'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectCreate */
static int tolua_lua_maapi_mosync_SysRectCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  void* tolua_ret = (void*)  SysRectCreate();
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectGetLeft */
static int tolua_lua_maapi_mosync_SysRectGetLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* rect = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysRectGetLeft(rect);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectGetLeft'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectGetTop */
static int tolua_lua_maapi_mosync_SysRectGetTop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* rect = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysRectGetTop(rect);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectGetTop'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectGetWidth */
static int tolua_lua_maapi_mosync_SysRectGetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* rect = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysRectGetWidth(rect);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectGetWidth'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectGetHeight */
static int tolua_lua_maapi_mosync_SysRectGetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* rect = ((void*)  tolua_touserdata(tolua_S,1,0));
 {
  int tolua_ret = (int)  SysRectGetHeight(rect);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectGetHeight'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectSetLeft */
static int tolua_lua_maapi_mosync_SysRectSetLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* rect = ((void*)  tolua_touserdata(tolua_S,1,0));
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SysRectSetLeft(rect,left);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectSetLeft'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectSetTop */
static int tolua_lua_maapi_mosync_SysRectSetTop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* rect = ((void*)  tolua_touserdata(tolua_S,1,0));
  int top = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SysRectSetTop(rect,top);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectSetTop'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectSetWidth */
static int tolua_lua_maapi_mosync_SysRectSetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* rect = ((void*)  tolua_touserdata(tolua_S,1,0));
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SysRectSetWidth(rect,width);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectSetWidth'.",&tolua_err);
 return 0;
#endif
}

/* function: SysRectSetHeight */
static int tolua_lua_maapi_mosync_SysRectSetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  void* rect = ((void*)  tolua_touserdata(tolua_S,1,0));
  int height = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SysRectSetHeight(rect,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysRectSetHeight'.",&tolua_err);
 return 0;
#endif
}

/* function: SysCopyDataCreate */
static int tolua_lua_maapi_mosync_SysCopyDataCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle dst = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
  int dstOffset = ((int)  tolua_tonumber(tolua_S,2,0));
  MAHandle src = ((MAHandle)  tolua_tonumber(tolua_S,3,0));
  int srcOffset = ((int)  tolua_tonumber(tolua_S,4,0));
  int size = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  void* tolua_ret = (void*)  SysCopyDataCreate(dst,dstOffset,src,srcOffset,size);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysCopyDataCreate'.",&tolua_err);
 return 0;
#endif
}

/* function: SysScreenSetColor */
static int tolua_lua_maapi_mosync_SysScreenSetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int red = ((int)  tolua_tonumber(tolua_S,1,0));
  int green = ((int)  tolua_tonumber(tolua_S,2,0));
  int blue = ((int)  tolua_tonumber(tolua_S,3,0));
 {
  SysScreenSetColor(red,green,blue);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysScreenSetColor'.",&tolua_err);
 return 0;
#endif
}

/* function: SysScreenDrawText */
static int tolua_lua_maapi_mosync_SysScreenDrawText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isuserdata(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* text = ((const char*)  tolua_tostring(tolua_S,1,0));
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  void* font = ((void*)  tolua_touserdata(tolua_S,4,0));
 {
  SysScreenDrawText(text,x,y,font);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysScreenDrawText'.",&tolua_err);
 return 0;
#endif
}

/* function: SysStringCharToWideChar */
static int tolua_lua_maapi_mosync_SysStringCharToWideChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,1,0));
 {
  void* tolua_ret = (void*)  SysStringCharToWideChar(str);
 tolua_pushuserdata(tolua_S,(void*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysStringCharToWideChar'.",&tolua_err);
 return 0;
#endif
}

/* function: SysStringWideCharToChar */
static int tolua_lua_maapi_mosync_SysStringWideCharToChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isuserdata(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const void* wstr = ((const void*)  tolua_touserdata(tolua_S,1,0));
 {
  char* tolua_ret = (char*)  SysStringWideCharToChar(wstr);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysStringWideCharToChar'.",&tolua_err);
 return 0;
#endif
}

/* function: SysLoadStringResource */
static int tolua_lua_maapi_mosync_SysLoadStringResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MAHandle handle = ((MAHandle)  tolua_tonumber(tolua_S,1,0));
 {
  char* tolua_ret = (char*)  SysLoadStringResource(handle);
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SysLoadStringResource'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_lua_maapi (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"mosync",0);
 tolua_beginmodule(tolua_S,"mosync");
 tolua_constant(tolua_S,"TRANS_NONE",TRANS_NONE);
 tolua_constant(tolua_S,"TRANS_ROT90",TRANS_ROT90);
 tolua_constant(tolua_S,"TRANS_ROT180",TRANS_ROT180);
 tolua_constant(tolua_S,"TRANS_ROT270",TRANS_ROT270);
 tolua_constant(tolua_S,"TRANS_MIRROR",TRANS_MIRROR);
 tolua_constant(tolua_S,"TRANS_MIRROR_ROT90",TRANS_MIRROR_ROT90);
 tolua_constant(tolua_S,"TRANS_MIRROR_ROT180",TRANS_MIRROR_ROT180);
 tolua_constant(tolua_S,"TRANS_MIRROR_ROT270",TRANS_MIRROR_ROT270);
 tolua_constant(tolua_S,"HANDLE_SCREEN",HANDLE_SCREEN);
 tolua_constant(tolua_S,"HANDLE_LOCAL",HANDLE_LOCAL);
 tolua_constant(tolua_S,"RES_OUT_OF_MEMORY",RES_OUT_OF_MEMORY);
 tolua_constant(tolua_S,"RES_BAD_INPUT",RES_BAD_INPUT);
 tolua_constant(tolua_S,"RES_OK",RES_OK);
 tolua_constant(tolua_S,"MAS_CREATE_IF_NECESSARY",MAS_CREATE_IF_NECESSARY);
 tolua_constant(tolua_S,"STERR_GENERIC",STERR_GENERIC);
 tolua_constant(tolua_S,"STERR_FULL",STERR_FULL);
 tolua_constant(tolua_S,"STERR_NONEXISTENT",STERR_NONEXISTENT);
 tolua_constant(tolua_S,"CONNERR_GENERIC",CONNERR_GENERIC);
 tolua_constant(tolua_S,"CONNERR_MAX",CONNERR_MAX);
 tolua_constant(tolua_S,"CONNERR_DNS",CONNERR_DNS);
 tolua_constant(tolua_S,"CONNERR_INTERNAL",CONNERR_INTERNAL);
 tolua_constant(tolua_S,"CONNERR_CLOSED",CONNERR_CLOSED);
 tolua_constant(tolua_S,"CONNERR_READONLY",CONNERR_READONLY);
 tolua_constant(tolua_S,"CONNERR_FORBIDDEN",CONNERR_FORBIDDEN);
 tolua_constant(tolua_S,"CONNERR_UNINITIALIZED",CONNERR_UNINITIALIZED);
 tolua_constant(tolua_S,"CONNERR_CONLEN",CONNERR_CONLEN);
 tolua_constant(tolua_S,"CONNERR_URL",CONNERR_URL);
 tolua_constant(tolua_S,"CONNERR_UNAVAILABLE",CONNERR_UNAVAILABLE);
 tolua_constant(tolua_S,"CONNERR_CANCELED",CONNERR_CANCELED);
 tolua_constant(tolua_S,"CONNERR_PROTOCOL",CONNERR_PROTOCOL);
 tolua_constant(tolua_S,"CONNERR_NETWORK",CONNERR_NETWORK);
 tolua_constant(tolua_S,"CONNERR_NOHEADER",CONNERR_NOHEADER);
 tolua_constant(tolua_S,"CONNERR_NOTFOUND",CONNERR_NOTFOUND);
 tolua_constant(tolua_S,"CONNERR_SSL",CONNERR_SSL);
 tolua_constant(tolua_S,"CONNERR_USER",CONNERR_USER);
 tolua_constant(tolua_S,"CONNOP_READ",CONNOP_READ);
 tolua_constant(tolua_S,"CONNOP_WRITE",CONNOP_WRITE);
 tolua_constant(tolua_S,"CONNOP_CONNECT",CONNOP_CONNECT);
 tolua_constant(tolua_S,"CONNOP_FINISH",CONNOP_FINISH);
 tolua_constant(tolua_S,"CONNOP_ACCEPT",CONNOP_ACCEPT);
 tolua_constant(tolua_S,"CONN_MAX",CONN_MAX);
 tolua_constant(tolua_S,"BTADDR_LEN",BTADDR_LEN);
 tolua_constant(tolua_S,"CONN_FAMILY_INET4",CONN_FAMILY_INET4);
 tolua_constant(tolua_S,"CONN_FAMILY_BT",CONN_FAMILY_BT);
 tolua_constant(tolua_S,"HTTP_GET",HTTP_GET);
 tolua_constant(tolua_S,"HTTP_POST",HTTP_POST);
 tolua_constant(tolua_S,"HTTP_HEAD",HTTP_HEAD);
 tolua_constant(tolua_S,"HTTP_PUT",HTTP_PUT);
 tolua_constant(tolua_S,"HTTP_DELETE",HTTP_DELETE);
 tolua_constant(tolua_S,"MA_RESOURCE_OPEN",MA_RESOURCE_OPEN);
 tolua_constant(tolua_S,"MA_RESOURCE_CLOSE",MA_RESOURCE_CLOSE);
 tolua_constant(tolua_S,"MAK_UNKNOWN",MAK_UNKNOWN);
 tolua_constant(tolua_S,"MAK_FIRST",MAK_FIRST);
 tolua_constant(tolua_S,"MAK_BACKSPACE",MAK_BACKSPACE);
 tolua_constant(tolua_S,"MAK_TAB",MAK_TAB);
 tolua_constant(tolua_S,"MAK_CLEAR",MAK_CLEAR);
 tolua_constant(tolua_S,"MAK_RETURN",MAK_RETURN);
 tolua_constant(tolua_S,"MAK_PAUSE",MAK_PAUSE);
 tolua_constant(tolua_S,"MAK_ESCAPE",MAK_ESCAPE);
 tolua_constant(tolua_S,"MAK_SPACE",MAK_SPACE);
 tolua_constant(tolua_S,"MAK_EXCLAIM",MAK_EXCLAIM);
 tolua_constant(tolua_S,"MAK_QUOTEDBL",MAK_QUOTEDBL);
 tolua_constant(tolua_S,"MAK_POUND",MAK_POUND);
 tolua_constant(tolua_S,"MAK_HASH",MAK_HASH);
 tolua_constant(tolua_S,"MAK_GRID",MAK_GRID);
 tolua_constant(tolua_S,"MAK_DOLLAR",MAK_DOLLAR);
 tolua_constant(tolua_S,"MAK_AMPERSAND",MAK_AMPERSAND);
 tolua_constant(tolua_S,"MAK_QUOTE",MAK_QUOTE);
 tolua_constant(tolua_S,"MAK_LEFTPAREN",MAK_LEFTPAREN);
 tolua_constant(tolua_S,"MAK_RIGHTPAREN",MAK_RIGHTPAREN);
 tolua_constant(tolua_S,"MAK_ASTERISK",MAK_ASTERISK);
 tolua_constant(tolua_S,"MAK_STAR",MAK_STAR);
 tolua_constant(tolua_S,"MAK_PLUS",MAK_PLUS);
 tolua_constant(tolua_S,"MAK_COMMA",MAK_COMMA);
 tolua_constant(tolua_S,"MAK_MINUS",MAK_MINUS);
 tolua_constant(tolua_S,"MAK_PERIOD",MAK_PERIOD);
 tolua_constant(tolua_S,"MAK_SLASH",MAK_SLASH);
 tolua_constant(tolua_S,"MAK_0",MAK_0);
 tolua_constant(tolua_S,"MAK_1",MAK_1);
 tolua_constant(tolua_S,"MAK_2",MAK_2);
 tolua_constant(tolua_S,"MAK_3",MAK_3);
 tolua_constant(tolua_S,"MAK_4",MAK_4);
 tolua_constant(tolua_S,"MAK_5",MAK_5);
 tolua_constant(tolua_S,"MAK_6",MAK_6);
 tolua_constant(tolua_S,"MAK_7",MAK_7);
 tolua_constant(tolua_S,"MAK_8",MAK_8);
 tolua_constant(tolua_S,"MAK_9",MAK_9);
 tolua_constant(tolua_S,"MAK_COLON",MAK_COLON);
 tolua_constant(tolua_S,"MAK_SEMICOLON",MAK_SEMICOLON);
 tolua_constant(tolua_S,"MAK_LESS",MAK_LESS);
 tolua_constant(tolua_S,"MAK_EQUALS",MAK_EQUALS);
 tolua_constant(tolua_S,"MAK_GREATER",MAK_GREATER);
 tolua_constant(tolua_S,"MAK_QUESTION",MAK_QUESTION);
 tolua_constant(tolua_S,"MAK_AT",MAK_AT);
 tolua_constant(tolua_S,"MAK_LEFTBRACKET",MAK_LEFTBRACKET);
 tolua_constant(tolua_S,"MAK_BACKSLASH",MAK_BACKSLASH);
 tolua_constant(tolua_S,"MAK_RIGHTBRACKET",MAK_RIGHTBRACKET);
 tolua_constant(tolua_S,"MAK_CARET",MAK_CARET);
 tolua_constant(tolua_S,"MAK_UNDERSCORE",MAK_UNDERSCORE);
 tolua_constant(tolua_S,"MAK_BACKQUOTE",MAK_BACKQUOTE);
 tolua_constant(tolua_S,"MAK_A",MAK_A);
 tolua_constant(tolua_S,"MAK_B",MAK_B);
 tolua_constant(tolua_S,"MAK_C",MAK_C);
 tolua_constant(tolua_S,"MAK_D",MAK_D);
 tolua_constant(tolua_S,"MAK_E",MAK_E);
 tolua_constant(tolua_S,"MAK_F",MAK_F);
 tolua_constant(tolua_S,"MAK_G",MAK_G);
 tolua_constant(tolua_S,"MAK_H",MAK_H);
 tolua_constant(tolua_S,"MAK_I",MAK_I);
 tolua_constant(tolua_S,"MAK_J",MAK_J);
 tolua_constant(tolua_S,"MAK_K",MAK_K);
 tolua_constant(tolua_S,"MAK_L",MAK_L);
 tolua_constant(tolua_S,"MAK_M",MAK_M);
 tolua_constant(tolua_S,"MAK_N",MAK_N);
 tolua_constant(tolua_S,"MAK_O",MAK_O);
 tolua_constant(tolua_S,"MAK_P",MAK_P);
 tolua_constant(tolua_S,"MAK_Q",MAK_Q);
 tolua_constant(tolua_S,"MAK_R",MAK_R);
 tolua_constant(tolua_S,"MAK_S",MAK_S);
 tolua_constant(tolua_S,"MAK_T",MAK_T);
 tolua_constant(tolua_S,"MAK_U",MAK_U);
 tolua_constant(tolua_S,"MAK_V",MAK_V);
 tolua_constant(tolua_S,"MAK_W",MAK_W);
 tolua_constant(tolua_S,"MAK_X",MAK_X);
 tolua_constant(tolua_S,"MAK_Y",MAK_Y);
 tolua_constant(tolua_S,"MAK_Z",MAK_Z);
 tolua_constant(tolua_S,"MAK_DELETE",MAK_DELETE);
 tolua_constant(tolua_S,"MAK_KP0",MAK_KP0);
 tolua_constant(tolua_S,"MAK_KP1",MAK_KP1);
 tolua_constant(tolua_S,"MAK_KP2",MAK_KP2);
 tolua_constant(tolua_S,"MAK_KP3",MAK_KP3);
 tolua_constant(tolua_S,"MAK_KP4",MAK_KP4);
 tolua_constant(tolua_S,"MAK_KP5",MAK_KP5);
 tolua_constant(tolua_S,"MAK_KP6",MAK_KP6);
 tolua_constant(tolua_S,"MAK_KP7",MAK_KP7);
 tolua_constant(tolua_S,"MAK_KP8",MAK_KP8);
 tolua_constant(tolua_S,"MAK_KP9",MAK_KP9);
 tolua_constant(tolua_S,"MAK_KP_PERIOD",MAK_KP_PERIOD);
 tolua_constant(tolua_S,"MAK_KP_DIVIDE",MAK_KP_DIVIDE);
 tolua_constant(tolua_S,"MAK_KP_MULTIPLY",MAK_KP_MULTIPLY);
 tolua_constant(tolua_S,"MAK_KP_MINUS",MAK_KP_MINUS);
 tolua_constant(tolua_S,"MAK_KP_PLUS",MAK_KP_PLUS);
 tolua_constant(tolua_S,"MAK_KP_ENTER",MAK_KP_ENTER);
 tolua_constant(tolua_S,"MAK_KP_EQUALS",MAK_KP_EQUALS);
 tolua_constant(tolua_S,"MAK_UP",MAK_UP);
 tolua_constant(tolua_S,"MAK_DOWN",MAK_DOWN);
 tolua_constant(tolua_S,"MAK_RIGHT",MAK_RIGHT);
 tolua_constant(tolua_S,"MAK_LEFT",MAK_LEFT);
 tolua_constant(tolua_S,"MAK_INSERT",MAK_INSERT);
 tolua_constant(tolua_S,"MAK_HOME",MAK_HOME);
 tolua_constant(tolua_S,"MAK_END",MAK_END);
 tolua_constant(tolua_S,"MAK_PAGEUP",MAK_PAGEUP);
 tolua_constant(tolua_S,"MAK_PAGEDOWN",MAK_PAGEDOWN);
 tolua_constant(tolua_S,"MAK_FIRE",MAK_FIRE);
 tolua_constant(tolua_S,"MAK_SOFTLEFT",MAK_SOFTLEFT);
 tolua_constant(tolua_S,"MAK_SOFTRIGHT",MAK_SOFTRIGHT);
 tolua_constant(tolua_S,"MAK_PEN",MAK_PEN);
 tolua_constant(tolua_S,"MAK_BACK",MAK_BACK);
 tolua_constant(tolua_S,"MAK_MENU",MAK_MENU);
 tolua_constant(tolua_S,"MAK_RSHIFT",MAK_RSHIFT);
 tolua_constant(tolua_S,"MAK_LSHIFT",MAK_LSHIFT);
 tolua_constant(tolua_S,"MAK_RCTRL",MAK_RCTRL);
 tolua_constant(tolua_S,"MAK_LCTRL",MAK_LCTRL);
 tolua_constant(tolua_S,"MAK_RALT",MAK_RALT);
 tolua_constant(tolua_S,"MAK_LALT",MAK_LALT);
 tolua_constant(tolua_S,"MAK_SEARCH",MAK_SEARCH);
 tolua_constant(tolua_S,"MAKB_LEFT",MAKB_LEFT);
 tolua_constant(tolua_S,"MAKB_UP",MAKB_UP);
 tolua_constant(tolua_S,"MAKB_RIGHT",MAKB_RIGHT);
 tolua_constant(tolua_S,"MAKB_DOWN",MAKB_DOWN);
 tolua_constant(tolua_S,"MAKB_FIRE",MAKB_FIRE);
 tolua_constant(tolua_S,"MAKB_SOFTLEFT",MAKB_SOFTLEFT);
 tolua_constant(tolua_S,"MAKB_SOFTRIGHT",MAKB_SOFTRIGHT);
 tolua_constant(tolua_S,"MAKB_0",MAKB_0);
 tolua_constant(tolua_S,"MAKB_1",MAKB_1);
 tolua_constant(tolua_S,"MAKB_2",MAKB_2);
 tolua_constant(tolua_S,"MAKB_3",MAKB_3);
 tolua_constant(tolua_S,"MAKB_4",MAKB_4);
 tolua_constant(tolua_S,"MAKB_5",MAKB_5);
 tolua_constant(tolua_S,"MAKB_6",MAKB_6);
 tolua_constant(tolua_S,"MAKB_7",MAKB_7);
 tolua_constant(tolua_S,"MAKB_8",MAKB_8);
 tolua_constant(tolua_S,"MAKB_9",MAKB_9);
 tolua_constant(tolua_S,"MAKB_ASTERISK",MAKB_ASTERISK);
 tolua_constant(tolua_S,"MAKB_STAR",MAKB_STAR);
 tolua_constant(tolua_S,"MAKB_HASH",MAKB_HASH);
 tolua_constant(tolua_S,"MAKB_POUND",MAKB_POUND);
 tolua_constant(tolua_S,"MAKB_GRID",MAKB_GRID);
 tolua_constant(tolua_S,"MAKB_CLEAR",MAKB_CLEAR);
 tolua_constant(tolua_S,"EVENT_BUFFER_SIZE",EVENT_BUFFER_SIZE);
 tolua_constant(tolua_S,"EVENT_CLOSE_TIMEOUT",EVENT_CLOSE_TIMEOUT);
 tolua_constant(tolua_S,"EVENT_TYPE_CLOSE",EVENT_TYPE_CLOSE);
 tolua_constant(tolua_S,"EVENT_TYPE_KEY_PRESSED",EVENT_TYPE_KEY_PRESSED);
 tolua_constant(tolua_S,"EVENT_TYPE_KEY_RELEASED",EVENT_TYPE_KEY_RELEASED);
 tolua_constant(tolua_S,"EVENT_TYPE_CONN",EVENT_TYPE_CONN);
 tolua_constant(tolua_S,"EVENT_TYPE_BT",EVENT_TYPE_BT);
 tolua_constant(tolua_S,"EVENT_TYPE_POINTER_PRESSED",EVENT_TYPE_POINTER_PRESSED);
 tolua_constant(tolua_S,"EVENT_TYPE_POINTER_RELEASED",EVENT_TYPE_POINTER_RELEASED);
 tolua_constant(tolua_S,"EVENT_TYPE_POINTER_DRAGGED",EVENT_TYPE_POINTER_DRAGGED);
 tolua_constant(tolua_S,"EVENT_TYPE_FOCUS_LOST",EVENT_TYPE_FOCUS_LOST);
 tolua_constant(tolua_S,"EVENT_TYPE_FOCUS_GAINED",EVENT_TYPE_FOCUS_GAINED);
 tolua_constant(tolua_S,"EVENT_TYPE_LOCATION",EVENT_TYPE_LOCATION);
 tolua_constant(tolua_S,"EVENT_TYPE_LOCATION_PROVIDER",EVENT_TYPE_LOCATION_PROVIDER);
 tolua_constant(tolua_S,"EVENT_TYPE_AUDIO_PREPARED",EVENT_TYPE_AUDIO_PREPARED);
 tolua_constant(tolua_S,"EVENT_TYPE_AUDIO_COMPLETED",EVENT_TYPE_AUDIO_COMPLETED);
 tolua_constant(tolua_S,"EVENT_TYPE_SCREEN_CHANGED",EVENT_TYPE_SCREEN_CHANGED);
 tolua_constant(tolua_S,"EVENT_TYPE_CHAR",EVENT_TYPE_CHAR);
 tolua_constant(tolua_S,"EVENT_TYPE_TEXTBOX",EVENT_TYPE_TEXTBOX);
 tolua_constant(tolua_S,"EVENT_TYPE_HOMESCREEN_SHOWN",EVENT_TYPE_HOMESCREEN_SHOWN);
 tolua_constant(tolua_S,"EVENT_TYPE_HOMESCREEN_HIDDEN",EVENT_TYPE_HOMESCREEN_HIDDEN);
 tolua_constant(tolua_S,"EVENT_TYPE_SCREEN_STATE_ON",EVENT_TYPE_SCREEN_STATE_ON);
 tolua_constant(tolua_S,"EVENT_TYPE_SCREEN_STATE_OFF",EVENT_TYPE_SCREEN_STATE_OFF);
 tolua_constant(tolua_S,"EVENT_TYPE_WIDGET",EVENT_TYPE_WIDGET);
 tolua_constant(tolua_S,"EVENT_TYPE_BLUETOOTH_TURNED_OFF",EVENT_TYPE_BLUETOOTH_TURNED_OFF);
 tolua_constant(tolua_S,"EVENT_TYPE_BLUETOOTH_TURNED_ON",EVENT_TYPE_BLUETOOTH_TURNED_ON);
 tolua_constant(tolua_S,"EVENT_TYPE_IMAGE_PICKER",EVENT_TYPE_IMAGE_PICKER);
 tolua_constant(tolua_S,"EVENT_TYPE_SMS",EVENT_TYPE_SMS);
 tolua_constant(tolua_S,"EVENT_TYPE_SENSOR",EVENT_TYPE_SENSOR);
 tolua_constant(tolua_S,"EVENT_TYPE_ALERT",EVENT_TYPE_ALERT);
 tolua_constant(tolua_S,"EVENT_TYPE_NFC_TAG_RECEIVED",EVENT_TYPE_NFC_TAG_RECEIVED);
 tolua_constant(tolua_S,"EVENT_TYPE_NFC_TAG_DATA_READ",EVENT_TYPE_NFC_TAG_DATA_READ);
 tolua_constant(tolua_S,"EVENT_TYPE_NFC_TAG_DATA_WRITTEN",EVENT_TYPE_NFC_TAG_DATA_WRITTEN);
 tolua_constant(tolua_S,"EVENT_TYPE_NFC_BATCH_OP",EVENT_TYPE_NFC_BATCH_OP);
 tolua_constant(tolua_S,"EVENT_TYPE_NFC_TAG_AUTH_COMPLETE",EVENT_TYPE_NFC_TAG_AUTH_COMPLETE);
 tolua_constant(tolua_S,"EVENT_TYPE_NFC_TAG_READ_ONLY",EVENT_TYPE_NFC_TAG_READ_ONLY);
 tolua_constant(tolua_S,"EVENT_TYPE_OPTIONS_BOX_BUTTON_CLICKED",EVENT_TYPE_OPTIONS_BOX_BUTTON_CLICKED);
 tolua_constant(tolua_S,"EVENT_TYPE_ADS_BANNER",EVENT_TYPE_ADS_BANNER);
 tolua_constant(tolua_S,"EVENT_TYPE_LOCAL_NOTIFICATION",EVENT_TYPE_LOCAL_NOTIFICATION);
 tolua_constant(tolua_S,"EVENT_TYPE_PUSH_NOTIFICATION_REGISTRATION",EVENT_TYPE_PUSH_NOTIFICATION_REGISTRATION);
 tolua_constant(tolua_S,"EVENT_TYPE_PUSH_NOTIFICATION_UNREGISTRATION",EVENT_TYPE_PUSH_NOTIFICATION_UNREGISTRATION);
 tolua_constant(tolua_S,"EVENT_TYPE_PUSH_NOTIFICATION",EVENT_TYPE_PUSH_NOTIFICATION);
 tolua_constant(tolua_S,"EVENT_TYPE_CAPTURE",EVENT_TYPE_CAPTURE);
 tolua_constant(tolua_S,"EVENT_TYPE_PURCHASE",EVENT_TYPE_PURCHASE);
 tolua_constant(tolua_S,"EVENT_TYPE_NETWORK",EVENT_TYPE_NETWORK);
 tolua_constant(tolua_S,"RUNTIME_MORE",RUNTIME_MORE);
 tolua_constant(tolua_S,"RUNTIME_JAVA",RUNTIME_JAVA);
 tolua_constant(tolua_S,"RUNTIME_SYMBIAN",RUNTIME_SYMBIAN);
 tolua_constant(tolua_S,"RUNTIME_WINCE",RUNTIME_WINCE);
 tolua_constant(tolua_S,"REPORT_PANIC",REPORT_PANIC);
 tolua_constant(tolua_S,"REPORT_EXCEPTION",REPORT_EXCEPTION);
 tolua_constant(tolua_S,"REPORT_PLATFORM_CODE",REPORT_PLATFORM_CODE);
 tolua_constant(tolua_S,"REPORT_USER_PANIC",REPORT_USER_PANIC);
 tolua_constant(tolua_S,"REPORT_TIMEOUT",REPORT_TIMEOUT);
 tolua_constant(tolua_S,"MA_EXTENSION_MODULE_UNAVAILABLE",MA_EXTENSION_MODULE_UNAVAILABLE);
 tolua_constant(tolua_S,"MA_EXTENSION_FUNCTION_UNAVAILABLE",MA_EXTENSION_FUNCTION_UNAVAILABLE);
 tolua_constant(tolua_S,"FONT_TYPE_SERIF",FONT_TYPE_SERIF);
 tolua_constant(tolua_S,"FONT_TYPE_SANS_SERIF",FONT_TYPE_SANS_SERIF);
 tolua_constant(tolua_S,"FONT_TYPE_MONOSPACE",FONT_TYPE_MONOSPACE);
 tolua_constant(tolua_S,"FONT_STYLE_NORMAL",FONT_STYLE_NORMAL);
 tolua_constant(tolua_S,"FONT_STYLE_BOLD",FONT_STYLE_BOLD);
 tolua_constant(tolua_S,"FONT_STYLE_ITALIC",FONT_STYLE_ITALIC);
 tolua_constant(tolua_S,"RES_FONT_OK",RES_FONT_OK);
 tolua_constant(tolua_S,"RES_FONT_INVALID_HANDLE",RES_FONT_INVALID_HANDLE);
 tolua_constant(tolua_S,"RES_FONT_INDEX_OUT_OF_BOUNDS",RES_FONT_INDEX_OUT_OF_BOUNDS);
 tolua_constant(tolua_S,"RES_FONT_NO_TYPE_STYLE_COMBINATION",RES_FONT_NO_TYPE_STYLE_COMBINATION);
 tolua_constant(tolua_S,"RES_FONT_NAME_NONEXISTENT",RES_FONT_NAME_NONEXISTENT);
 tolua_constant(tolua_S,"RES_FONT_LIST_NOT_INITIALIZED",RES_FONT_LIST_NOT_INITIALIZED);
 tolua_constant(tolua_S,"RES_FONT_INSUFFICIENT_BUFFER",RES_FONT_INSUFFICIENT_BUFFER);
 tolua_constant(tolua_S,"RES_FONT_INVALID_SIZE",RES_FONT_INVALID_SIZE);
 tolua_constant(tolua_S,"RES_FONT_DELETE_DENIED",RES_FONT_DELETE_DENIED);
 tolua_constant(tolua_S,"MA_LOC_NONE",MA_LOC_NONE);
 tolua_constant(tolua_S,"MA_LOC_INVALID",MA_LOC_INVALID);
 tolua_constant(tolua_S,"MA_LOC_UNQUALIFIED",MA_LOC_UNQUALIFIED);
 tolua_constant(tolua_S,"MA_LOC_QUALIFIED",MA_LOC_QUALIFIED);
 tolua_constant(tolua_S,"MA_LPS_AVAILABLE",MA_LPS_AVAILABLE);
 tolua_constant(tolua_S,"MA_LPS_TEMPORARILY_UNAVAILABLE",MA_LPS_TEMPORARILY_UNAVAILABLE);
 tolua_constant(tolua_S,"MA_LPS_OUT_OF_SERVICE",MA_LPS_OUT_OF_SERVICE);
 tolua_constant(tolua_S,"MA_ACCESS_READ",MA_ACCESS_READ);
 tolua_constant(tolua_S,"MA_ACCESS_READ_WRITE",MA_ACCESS_READ_WRITE);
 tolua_constant(tolua_S,"MA_SEEK_SET",MA_SEEK_SET);
 tolua_constant(tolua_S,"MA_SEEK_CUR",MA_SEEK_CUR);
 tolua_constant(tolua_S,"MA_SEEK_END",MA_SEEK_END);
 tolua_constant(tolua_S,"MA_FL_SORT_NONE",MA_FL_SORT_NONE);
 tolua_constant(tolua_S,"MA_FL_SORT_DATE",MA_FL_SORT_DATE);
 tolua_constant(tolua_S,"MA_FL_SORT_NAME",MA_FL_SORT_NAME);
 tolua_constant(tolua_S,"MA_FL_SORT_SIZE",MA_FL_SORT_SIZE);
 tolua_constant(tolua_S,"MA_FL_ORDER_ASCENDING",MA_FL_ORDER_ASCENDING);
 tolua_constant(tolua_S,"MA_FL_ORDER_DESCENDING",MA_FL_ORDER_DESCENDING);
 tolua_constant(tolua_S,"MA_FERR_GENERIC",MA_FERR_GENERIC);
 tolua_constant(tolua_S,"MA_FERR_NOTFOUND",MA_FERR_NOTFOUND);
 tolua_constant(tolua_S,"MA_FERR_FORBIDDEN",MA_FERR_FORBIDDEN);
 tolua_constant(tolua_S,"MA_FERR_RENAME_FILESYSTEM",MA_FERR_RENAME_FILESYSTEM);
 tolua_constant(tolua_S,"MA_FERR_RENAME_DIRECTORY",MA_FERR_RENAME_DIRECTORY);
 tolua_constant(tolua_S,"MA_FERR_WRONG_TYPE",MA_FERR_WRONG_TYPE);
 tolua_constant(tolua_S,"MA_FERR_SORTING_UNSUPPORTED",MA_FERR_SORTING_UNSUPPORTED);
 tolua_constant(tolua_S,"MA_SMS_RESULT_SENT",MA_SMS_RESULT_SENT);
 tolua_constant(tolua_S,"MA_SMS_RESULT_NOT_SENT",MA_SMS_RESULT_NOT_SENT);
 tolua_constant(tolua_S,"MA_SMS_RESULT_DELIVERED",MA_SMS_RESULT_DELIVERED);
 tolua_constant(tolua_S,"MA_SMS_RESULT_NOT_DELIVERED",MA_SMS_RESULT_NOT_DELIVERED);
 tolua_constant(tolua_S,"MA_NETWORK_UNKNOWN",MA_NETWORK_UNKNOWN);
 tolua_constant(tolua_S,"MA_NETWORK_NO_SERVICE",MA_NETWORK_NO_SERVICE);
 tolua_constant(tolua_S,"MA_NETWORK_EMERGENCY_ONLY",MA_NETWORK_EMERGENCY_ONLY);
 tolua_constant(tolua_S,"MA_NETWORK_SEARCHING",MA_NETWORK_SEARCHING);
 tolua_constant(tolua_S,"MA_NETWORK_BUSY",MA_NETWORK_BUSY);
 tolua_constant(tolua_S,"MA_NETWORK_HOME",MA_NETWORK_HOME);
 tolua_constant(tolua_S,"MA_NETWORK_DENIED",MA_NETWORK_DENIED);
 tolua_constant(tolua_S,"MA_NETWORK_ROAMING",MA_NETWORK_ROAMING);
 tolua_constant(tolua_S,"MA_IAP_METHOD_STANDARD",MA_IAP_METHOD_STANDARD);
 tolua_constant(tolua_S,"MA_IAP_METHOD_WLAN",MA_IAP_METHOD_WLAN);
 tolua_constant(tolua_S,"MA_IAP_FILTER_NOT_WLAN",MA_IAP_FILTER_NOT_WLAN);
 tolua_constant(tolua_S,"MA_IAP_FILTER_WLAN",MA_IAP_FILTER_WLAN);
 tolua_constant(tolua_S,"MA_IAP_FILTER_ALL",MA_IAP_FILTER_ALL);
 tolua_constant(tolua_S,"MA_CAMERA_CONST_BACK_CAMERA",MA_CAMERA_CONST_BACK_CAMERA);
 tolua_constant(tolua_S,"MA_CAMERA_CONST_FRONT_CAMERA",MA_CAMERA_CONST_FRONT_CAMERA);
 tolua_constant(tolua_S,"MA_CAMERA_RES_OK",MA_CAMERA_RES_OK);
 tolua_constant(tolua_S,"MA_CAMERA_RES_FAILED",MA_CAMERA_RES_FAILED);
 tolua_constant(tolua_S,"MA_CAMERA_RES_NOT_STARTED",MA_CAMERA_RES_NOT_STARTED);
 tolua_constant(tolua_S,"MA_CAMERA_RES_PROPERTY_NOTSUPPORTED",MA_CAMERA_RES_PROPERTY_NOTSUPPORTED);
 tolua_constant(tolua_S,"MA_CAMERA_RES_INVALID_PROPERTY_VALUE",MA_CAMERA_RES_INVALID_PROPERTY_VALUE);
 tolua_constant(tolua_S,"MA_CAMERA_RES_VALUE_NOTSUPPORTED",MA_CAMERA_RES_VALUE_NOTSUPPORTED);
 tolua_constant_string(tolua_S,"MA_CAMERA_FLASH_ON",MA_CAMERA_FLASH_ON);
 tolua_constant_string(tolua_S,"MA_CAMERA_FLASH_AUTO",MA_CAMERA_FLASH_AUTO);
 tolua_constant_string(tolua_S,"MA_CAMERA_FLASH_OFF",MA_CAMERA_FLASH_OFF);
 tolua_constant_string(tolua_S,"MA_CAMERA_FLASH_TORCH",MA_CAMERA_FLASH_TORCH);
 tolua_constant_string(tolua_S,"MA_CAMERA_FOCUS_AUTO",MA_CAMERA_FOCUS_AUTO);
 tolua_constant_string(tolua_S,"MA_CAMERA_FOCUS_INFINITY",MA_CAMERA_FOCUS_INFINITY);
 tolua_constant_string(tolua_S,"MA_CAMERA_FOCUS_MACRO",MA_CAMERA_FOCUS_MACRO);
 tolua_constant_string(tolua_S,"MA_CAMERA_FOCUS_FIXED",MA_CAMERA_FOCUS_FIXED);
 tolua_constant_string(tolua_S,"MA_CAMERA_IMAGE_JPEG",MA_CAMERA_IMAGE_JPEG);
 tolua_constant_string(tolua_S,"MA_CAMERA_IMAGE_RAW",MA_CAMERA_IMAGE_RAW);
 tolua_constant_string(tolua_S,"MA_CAMERA_FLASH_MODE",MA_CAMERA_FLASH_MODE);
 tolua_constant_string(tolua_S,"MA_CAMERA_FOCUS_MODE",MA_CAMERA_FOCUS_MODE);
 tolua_constant_string(tolua_S,"MA_CAMERA_IMAGE_FORMAT",MA_CAMERA_IMAGE_FORMAT);
 tolua_constant_string(tolua_S,"MA_CAMERA_ZOOM",MA_CAMERA_ZOOM);
 tolua_constant_string(tolua_S,"MA_CAMERA_MAX_ZOOM",MA_CAMERA_MAX_ZOOM);
 tolua_constant_string(tolua_S,"MA_CAMERA_ZOOM_SUPPORTED",MA_CAMERA_ZOOM_SUPPORTED);
 tolua_constant_string(tolua_S,"MA_CAMERA_FLASH_SUPPORTED",MA_CAMERA_FLASH_SUPPORTED);
 tolua_constant(tolua_S,"MA_TB_TYPE_ANY",MA_TB_TYPE_ANY);
 tolua_constant(tolua_S,"MA_TB_TYPE_EMAILADDR",MA_TB_TYPE_EMAILADDR);
 tolua_constant(tolua_S,"MA_TB_TYPE_NUMERIC",MA_TB_TYPE_NUMERIC);
 tolua_constant(tolua_S,"MA_TB_TYPE_PHONENUMBER",MA_TB_TYPE_PHONENUMBER);
 tolua_constant(tolua_S,"MA_TB_TYPE_URL",MA_TB_TYPE_URL);
 tolua_constant(tolua_S,"MA_TB_TYPE_DECIMAL",MA_TB_TYPE_DECIMAL);
 tolua_constant(tolua_S,"MA_TB_TYPE_SINGLE_LINE",MA_TB_TYPE_SINGLE_LINE);
 tolua_constant(tolua_S,"MA_TB_TYPE_MASK",MA_TB_TYPE_MASK);
 tolua_constant(tolua_S,"MA_TB_RES_OK",MA_TB_RES_OK);
 tolua_constant(tolua_S,"MA_TB_RES_CANCEL",MA_TB_RES_CANCEL);
 tolua_constant(tolua_S,"MA_TB_RES_TYPE_UNAVAILABLE",MA_TB_RES_TYPE_UNAVAILABLE);
 tolua_constant(tolua_S,"MA_TB_FLAG_PASSWORD",MA_TB_FLAG_PASSWORD);
 tolua_constant(tolua_S,"MA_TB_FLAG_UNEDITABLE",MA_TB_FLAG_UNEDITABLE);
 tolua_constant(tolua_S,"MA_TB_FLAG_SENSITIVE",MA_TB_FLAG_SENSITIVE);
 tolua_constant(tolua_S,"MA_TB_FLAG_NON_PREDICTIVE",MA_TB_FLAG_NON_PREDICTIVE);
 tolua_constant(tolua_S,"MA_TB_FLAG_INITIAL_CAPS_WORD",MA_TB_FLAG_INITIAL_CAPS_WORD);
 tolua_constant(tolua_S,"MA_TB_FLAG_INITIAL_CAPS_SENTENCE",MA_TB_FLAG_INITIAL_CAPS_SENTENCE);
 tolua_constant(tolua_S,"NOTIFICATION_TYPE_APPLICATION_LAUNCHER",NOTIFICATION_TYPE_APPLICATION_LAUNCHER);
 tolua_constant(tolua_S,"SCREEN_ORIENTATION_LANDSCAPE",SCREEN_ORIENTATION_LANDSCAPE);
 tolua_constant(tolua_S,"SCREEN_ORIENTATION_PORTRAIT",SCREEN_ORIENTATION_PORTRAIT);
 tolua_constant(tolua_S,"SCREEN_ORIENTATION_DYNAMIC",SCREEN_ORIENTATION_DYNAMIC);
 tolua_constant(tolua_S,"MA_SCREEN_ORIENTATION_PORTRAIT",MA_SCREEN_ORIENTATION_PORTRAIT);
 tolua_constant(tolua_S,"MA_SCREEN_ORIENTATION_PORTRAIT_UPSIDE_DOWN",MA_SCREEN_ORIENTATION_PORTRAIT_UPSIDE_DOWN);
 tolua_constant(tolua_S,"MA_SCREEN_ORIENTATION_LANDSCAPE_LEFT",MA_SCREEN_ORIENTATION_LANDSCAPE_LEFT);
 tolua_constant(tolua_S,"MA_SCREEN_ORIENTATION_LANDSCAPE_RIGHT",MA_SCREEN_ORIENTATION_LANDSCAPE_RIGHT);
 tolua_constant(tolua_S,"MA_SCREEN_ORIENTATION_RES_OK",MA_SCREEN_ORIENTATION_RES_OK);
 tolua_constant(tolua_S,"MA_SCREEN_ORIENTATION_RES_NOT_SUPPORTED",MA_SCREEN_ORIENTATION_RES_NOT_SUPPORTED);
 tolua_constant(tolua_S,"MA_SCREEN_ORIENTATION_RES_INVALID_VALUE",MA_SCREEN_ORIENTATION_RES_INVALID_VALUE);
 tolua_constant(tolua_S,"MA_WAKE_LOCK_ON",MA_WAKE_LOCK_ON);
 tolua_constant(tolua_S,"MA_WAKE_LOCK_OFF",MA_WAKE_LOCK_OFF);
 tolua_constant(tolua_S,"SENSOR_TYPE_ACCELEROMETER",SENSOR_TYPE_ACCELEROMETER);
 tolua_constant(tolua_S,"SENSOR_TYPE_MAGNETIC_FIELD",SENSOR_TYPE_MAGNETIC_FIELD);
 tolua_constant(tolua_S,"SENSOR_TYPE_ORIENTATION",SENSOR_TYPE_ORIENTATION);
 tolua_constant(tolua_S,"SENSOR_TYPE_GYROSCOPE",SENSOR_TYPE_GYROSCOPE);
 tolua_constant(tolua_S,"SENSOR_TYPE_PROXIMITY",SENSOR_TYPE_PROXIMITY);
 tolua_constant(tolua_S,"SENSOR_TYPE_COMPASS",SENSOR_TYPE_COMPASS);
 tolua_constant(tolua_S,"SENSOR_RATE_FASTEST",SENSOR_RATE_FASTEST);
 tolua_constant(tolua_S,"SENSOR_RATE_GAME",SENSOR_RATE_GAME);
 tolua_constant(tolua_S,"SENSOR_RATE_NORMAL",SENSOR_RATE_NORMAL);
 tolua_constant(tolua_S,"SENSOR_RATE_UI",SENSOR_RATE_UI);
 tolua_constant(tolua_S,"SENSOR_ERROR_NONE",SENSOR_ERROR_NONE);
 tolua_constant(tolua_S,"SENSOR_ERROR_NOT_AVAILABLE",SENSOR_ERROR_NOT_AVAILABLE);
 tolua_constant(tolua_S,"SENSOR_ERROR_INTERVAL_NOT_SET",SENSOR_ERROR_INTERVAL_NOT_SET);
 tolua_constant(tolua_S,"SENSOR_ERROR_ALREADY_ENABLED",SENSOR_ERROR_ALREADY_ENABLED);
 tolua_constant(tolua_S,"SENSOR_ERROR_NOT_ENABLED",SENSOR_ERROR_NOT_ENABLED);
 tolua_constant(tolua_S,"SENSOR_ERROR_CANNOT_DISABLE",SENSOR_ERROR_CANNOT_DISABLE);
 tolua_constant(tolua_S,"UIDEVICE_ORIENTATION_UNKNOWN",UIDEVICE_ORIENTATION_UNKNOWN);
 tolua_constant(tolua_S,"UIDEVICE_ORIENTATION_PORTRAIT",UIDEVICE_ORIENTATION_PORTRAIT);
 tolua_constant(tolua_S,"UIDEVICE_ORIENTATION_PORTRAIT_UPSIDE_DOWN",UIDEVICE_ORIENTATION_PORTRAIT_UPSIDE_DOWN);
 tolua_constant(tolua_S,"UIDEVICE_ORIENTATION_LANDSCAPE_LEFT",UIDEVICE_ORIENTATION_LANDSCAPE_LEFT);
 tolua_constant(tolua_S,"UIDEVICE_ORIENTATION_LANDSCAPE_RIGHT",UIDEVICE_ORIENTATION_LANDSCAPE_RIGHT);
 tolua_constant(tolua_S,"UIDEVICE_ORIENTATION_FACE_UP",UIDEVICE_ORIENTATION_FACE_UP);
 tolua_constant(tolua_S,"UIDEVICE_ORIENTATION_FACE_DOWN",UIDEVICE_ORIENTATION_FACE_DOWN);
 tolua_constant(tolua_S,"SENSOR_PROXIMITY_VALUE_FAR",SENSOR_PROXIMITY_VALUE_FAR);
 tolua_constant(tolua_S,"SENSOR_PROXIMITY_VALUE_NEAR",SENSOR_PROXIMITY_VALUE_NEAR);
 tolua_constant(tolua_S,"MA_NFC_NOT_AVAILABLE",MA_NFC_NOT_AVAILABLE);
 tolua_constant(tolua_S,"MA_NFC_NOT_ENABLED",MA_NFC_NOT_ENABLED);
 tolua_constant(tolua_S,"MA_NFC_INVALID_TAG_TYPE",MA_NFC_INVALID_TAG_TYPE);
 tolua_constant(tolua_S,"MA_NFC_TAG_CONNECTION_LOST",MA_NFC_TAG_CONNECTION_LOST);
 tolua_constant(tolua_S,"MA_NFC_TAG_NOT_CONNECTED",MA_NFC_TAG_NOT_CONNECTED);
 tolua_constant(tolua_S,"MA_NFC_FORMAT_FAILED",MA_NFC_FORMAT_FAILED);
 tolua_constant(tolua_S,"MA_NFC_TAG_IO_ERROR",MA_NFC_TAG_IO_ERROR);
 tolua_constant(tolua_S,"MA_NFC_TAG_TYPE_NDEF",MA_NFC_TAG_TYPE_NDEF);
 tolua_constant(tolua_S,"MA_NFC_TAG_TYPE_MIFARE_CL",MA_NFC_TAG_TYPE_MIFARE_CL);
 tolua_constant(tolua_S,"MA_NFC_TAG_TYPE_MIFARE_UL",MA_NFC_TAG_TYPE_MIFARE_UL);
 tolua_constant(tolua_S,"MA_NFC_TAG_TYPE_NFC_A",MA_NFC_TAG_TYPE_NFC_A);
 tolua_constant(tolua_S,"MA_NFC_TAG_TYPE_NFC_B",MA_NFC_TAG_TYPE_NFC_B);
 tolua_constant(tolua_S,"MA_NFC_TAG_TYPE_ISO_DEP",MA_NFC_TAG_TYPE_ISO_DEP);
 tolua_constant(tolua_S,"MA_NFC_TAG_TYPE_NDEF_FORMATTABLE",MA_NFC_TAG_TYPE_NDEF_FORMATTABLE);
 tolua_constant(tolua_S,"MA_NFC_NDEF_TNF_EMPTY",MA_NFC_NDEF_TNF_EMPTY);
 tolua_constant(tolua_S,"MA_NFC_NDEF_TNF_WELL_KNOWN",MA_NFC_NDEF_TNF_WELL_KNOWN);
 tolua_constant(tolua_S,"MA_NFC_NDEF_TNF_MIME_MEDIA",MA_NFC_NDEF_TNF_MIME_MEDIA);
 tolua_constant(tolua_S,"MA_NFC_NDEF_TNF_ABSOLUTE_URI",MA_NFC_NDEF_TNF_ABSOLUTE_URI);
 tolua_constant(tolua_S,"MA_NFC_NDEF_TNF_EXTERNAL_TYPE",MA_NFC_NDEF_TNF_EXTERNAL_TYPE);
 tolua_constant(tolua_S,"MA_NFC_NDEF_TNF_UNKNOWN",MA_NFC_NDEF_TNF_UNKNOWN);
 tolua_constant(tolua_S,"MA_NFC_NDEF_TNF_UNCHANGED",MA_NFC_NDEF_TNF_UNCHANGED);
 tolua_constant(tolua_S,"MA_NFC_NDEF_TNF_RESERVED",MA_NFC_NDEF_TNF_RESERVED);
 tolua_constant(tolua_S,"MA_NFC_MIFARE_KEY_A",MA_NFC_MIFARE_KEY_A);
 tolua_constant(tolua_S,"MA_NFC_MIFARE_KEY_B",MA_NFC_MIFARE_KEY_B);
 tolua_constant(tolua_S,"MA_DB_TYPE_NULL",MA_DB_TYPE_NULL);
 tolua_constant(tolua_S,"MA_DB_TYPE_INT",MA_DB_TYPE_INT);
 tolua_constant(tolua_S,"MA_DB_TYPE_INT64",MA_DB_TYPE_INT64);
 tolua_constant(tolua_S,"MA_DB_TYPE_DOUBLE",MA_DB_TYPE_DOUBLE);
 tolua_constant(tolua_S,"MA_DB_TYPE_BLOB",MA_DB_TYPE_BLOB);
 tolua_constant(tolua_S,"MA_DB_TYPE_DATA",MA_DB_TYPE_DATA);
 tolua_constant(tolua_S,"MA_DB_TYPE_TEXT",MA_DB_TYPE_TEXT);
 tolua_constant(tolua_S,"MA_DB_OK",MA_DB_OK);
 tolua_constant(tolua_S,"MA_DB_ERROR",MA_DB_ERROR);
 tolua_constant(tolua_S,"MA_DB_NO_ROW",MA_DB_NO_ROW);
 tolua_constant(tolua_S,"MA_DB_NULL",MA_DB_NULL);
 tolua_constant(tolua_S,"MA_AUDIO_DATA_STREAM",MA_AUDIO_DATA_STREAM);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_OK",MA_AUDIO_ERR_OK);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_INVALID_INSTANCE",MA_AUDIO_ERR_INVALID_INSTANCE);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_INVALID_DATA",MA_AUDIO_ERR_INVALID_DATA);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_INVALID_FILENAME",MA_AUDIO_ERR_INVALID_FILENAME);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_INVALID_FILE",MA_AUDIO_ERR_INVALID_FILE);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_STREAMING_NOT_SUPPORTED",MA_AUDIO_ERR_STREAMING_NOT_SUPPORTED);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_VOLUME_OUT_OF_RANGE",MA_AUDIO_ERR_VOLUME_OUT_OF_RANGE);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_POSITION_OUT_OF_RANGE",MA_AUDIO_ERR_POSITION_OUT_OF_RANGE);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_INVALID_SOUND_FORMAT",MA_AUDIO_ERR_INVALID_SOUND_FORMAT);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_OUT_OF_MEMORY",MA_AUDIO_ERR_OUT_OF_MEMORY);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_ALREADY_PREPARED",MA_AUDIO_ERR_ALREADY_PREPARED);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_PREPARE_FAILED",MA_AUDIO_ERR_PREPARE_FAILED);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_IS_PLAYING",MA_AUDIO_ERR_IS_PLAYING);
 tolua_constant(tolua_S,"MA_AUDIO_ERR_GENERIC",MA_AUDIO_ERR_GENERIC);
 tolua_constant(tolua_S,"MA_ADS_RES_OK",MA_ADS_RES_OK);
 tolua_constant(tolua_S,"MA_ADS_RES_INVALID_LAYOUT_HANDLE",MA_ADS_RES_INVALID_LAYOUT_HANDLE);
 tolua_constant(tolua_S,"MA_ADS_RES_INVALID_BANNER_HANDLE",MA_ADS_RES_INVALID_BANNER_HANDLE);
 tolua_constant(tolua_S,"MA_ADS_RES_INVALID_PROPERTY_NAME",MA_ADS_RES_INVALID_PROPERTY_NAME);
 tolua_constant(tolua_S,"MA_ADS_RES_INVALID_PROPERTY_VALUE",MA_ADS_RES_INVALID_PROPERTY_VALUE);
 tolua_constant(tolua_S,"MA_ADS_RES_INVALID_STRING_BUFFER_SIZE",MA_ADS_RES_INVALID_STRING_BUFFER_SIZE);
 tolua_constant(tolua_S,"MA_ADS_RES_ERROR",MA_ADS_RES_ERROR);
 tolua_constant(tolua_S,"MA_ADS_RES_UNSUPPORTED",MA_ADS_RES_UNSUPPORTED);
 tolua_constant(tolua_S,"MA_ADS_ERROR_INTERNAL",MA_ADS_ERROR_INTERNAL);
 tolua_constant(tolua_S,"MA_ADS_ERROR_INVALID_REQUEST",MA_ADS_ERROR_INVALID_REQUEST);
 tolua_constant(tolua_S,"MA_ADS_ERROR_NETWORK",MA_ADS_ERROR_NETWORK);
 tolua_constant(tolua_S,"MA_ADS_ERROR_NO_FILL",MA_ADS_ERROR_NO_FILL);
 tolua_constant(tolua_S,"MA_ADS_ERROR_CONFIGURATION",MA_ADS_ERROR_CONFIGURATION);
 tolua_constant(tolua_S,"MA_ADS_ERROR_NO_CONTENT",MA_ADS_ERROR_NO_CONTENT);
 tolua_constant(tolua_S,"MA_ADS_ERROR_APPLICATION_INACTIVE",MA_ADS_ERROR_APPLICATION_INACTIVE);
 tolua_constant_string(tolua_S,"MA_ADS_HEIGHT",MA_ADS_HEIGHT);
 tolua_constant_string(tolua_S,"MA_ADS_WIDTH",MA_ADS_WIDTH);
 tolua_constant_string(tolua_S,"MA_ADS_VISIBLE",MA_ADS_VISIBLE);
 tolua_constant_string(tolua_S,"MA_ADS_ENABLED",MA_ADS_ENABLED);
 tolua_constant_string(tolua_S,"MA_ADS_TEST_DEVICE",MA_ADS_TEST_DEVICE);
 tolua_constant_string(tolua_S,"MA_ADS_REQUEST_CONTENT",MA_ADS_REQUEST_CONTENT);
 tolua_constant_string(tolua_S,"MA_ADS_IS_READY",MA_ADS_IS_READY);
 tolua_constant_string(tolua_S,"MA_ADS_COLOR_BG",MA_ADS_COLOR_BG);
 tolua_constant_string(tolua_S,"MA_ADS_COLOR_BG_TOP",MA_ADS_COLOR_BG_TOP);
 tolua_constant_string(tolua_S,"MA_ADS_COLOR_BORDER",MA_ADS_COLOR_BORDER);
 tolua_constant_string(tolua_S,"MA_ADS_COLOR_LINK",MA_ADS_COLOR_LINK);
 tolua_constant_string(tolua_S,"MA_ADS_COLOR_TEXT",MA_ADS_COLOR_TEXT);
 tolua_constant_string(tolua_S,"MA_ADS_COLOR_URL",MA_ADS_COLOR_URL);
 tolua_constant(tolua_S,"MA_ADS_SIZE_BANNER",MA_ADS_SIZE_BANNER);
 tolua_constant(tolua_S,"MA_ADS_SIZE_RECT",MA_ADS_SIZE_RECT);
 tolua_constant(tolua_S,"MA_ADS_SIZE_IAB_BANNER",MA_ADS_SIZE_IAB_BANNER);
 tolua_constant(tolua_S,"MA_ADS_SIZE_LEADERBOARD",MA_ADS_SIZE_LEADERBOARD);
 tolua_constant(tolua_S,"MA_ADS_SIZE_WP7_XLARGE",MA_ADS_SIZE_WP7_XLARGE);
 tolua_constant(tolua_S,"MA_ADS_SIZE_WP7_XXLARGE",MA_ADS_SIZE_WP7_XXLARGE);
 tolua_constant(tolua_S,"MA_ADS_EVENT_FAILED",MA_ADS_EVENT_FAILED);
 tolua_constant(tolua_S,"MA_ADS_EVENT_LOADED",MA_ADS_EVENT_LOADED);
 tolua_constant(tolua_S,"MA_ADS_EVENT_ON_DISMISS",MA_ADS_EVENT_ON_DISMISS);
 tolua_constant(tolua_S,"MA_ADS_EVENT_ON_LEAVE_APPLICATION",MA_ADS_EVENT_ON_LEAVE_APPLICATION);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_OK",MA_NOTIFICATION_RES_OK);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_INVALID_HANDLE",MA_NOTIFICATION_RES_INVALID_HANDLE);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_INVALID_PROPERTY_NAME",MA_NOTIFICATION_RES_INVALID_PROPERTY_NAME);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_INVALID_PROPERTY_VALUE",MA_NOTIFICATION_RES_INVALID_PROPERTY_VALUE);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_INVALID_STRING_BUFFER_SIZE",MA_NOTIFICATION_RES_INVALID_STRING_BUFFER_SIZE);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_UNSUPPORTED",MA_NOTIFICATION_RES_UNSUPPORTED);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_ALREADY_SCHEDULED",MA_NOTIFICATION_RES_ALREADY_SCHEDULED);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_CANNOT_UNSCHEDULE",MA_NOTIFICATION_RES_CANNOT_UNSCHEDULE);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_ALREADY_REGISTERED",MA_NOTIFICATION_RES_ALREADY_REGISTERED);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_NOT_REGISTERED",MA_NOTIFICATION_RES_NOT_REGISTERED);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_IN_PROGRESS",MA_NOTIFICATION_RES_REGISTRATION_IN_PROGRESS);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_SERVICE_NOT_AVAILABLE",MA_NOTIFICATION_RES_REGISTRATION_SERVICE_NOT_AVAILABLE);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_ACCOUNT_MISSING",MA_NOTIFICATION_RES_REGISTRATION_ACCOUNT_MISSING);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_AUTHENTICATION_FAILED",MA_NOTIFICATION_RES_REGISTRATION_AUTHENTICATION_FAILED);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_TOO_MANY_REGISTRATIONS",MA_NOTIFICATION_RES_REGISTRATION_TOO_MANY_REGISTRATIONS);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_INVALID_SENDER",MA_NOTIFICATION_RES_REGISTRATION_INVALID_SENDER);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_PHONE_REGISTRATION_ERROR",MA_NOTIFICATION_RES_REGISTRATION_PHONE_REGISTRATION_ERROR);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_MESSAGE_BUF_TOO_SMALL",MA_NOTIFICATION_RES_REGISTRATION_MESSAGE_BUF_TOO_SMALL);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_REGISTRATION_NOT_CALLED",MA_NOTIFICATION_RES_REGISTRATION_NOT_CALLED);
 tolua_constant(tolua_S,"MA_NOTIFICATION_RES_ERROR",MA_NOTIFICATION_RES_ERROR);
 tolua_constant(tolua_S,"MA_NOTIFICATION_FLAG_INSISTENT",MA_NOTIFICATION_FLAG_INSISTENT);
 tolua_constant(tolua_S,"MA_NOTIFICATION_FLAG_NO_CLEAR",MA_NOTIFICATION_FLAG_NO_CLEAR);
 tolua_constant(tolua_S,"MA_NOTIFICATION_FLAG_HIGH_PRIORITY",MA_NOTIFICATION_FLAG_HIGH_PRIORITY);
 tolua_constant(tolua_S,"MA_NOTIFICATION_FLAG_AUTO_CANCEL",MA_NOTIFICATION_FLAG_AUTO_CANCEL);
 tolua_constant(tolua_S,"MA_NOTIFICATION_DISPLAY_FLAG_DEFAULT",MA_NOTIFICATION_DISPLAY_FLAG_DEFAULT);
 tolua_constant(tolua_S,"MA_NOTIFICATION_DISPLAY_FLAG_ANYTIME",MA_NOTIFICATION_DISPLAY_FLAG_ANYTIME);
 tolua_constant(tolua_S,"MA_NOTIFICATION_PUSH_TYPE_BADGE",MA_NOTIFICATION_PUSH_TYPE_BADGE);
 tolua_constant(tolua_S,"MA_NOTIFICATION_PUSH_TYPE_SOUND",MA_NOTIFICATION_PUSH_TYPE_SOUND);
 tolua_constant(tolua_S,"MA_NOTIFICATION_PUSH_TYPE_ALERT",MA_NOTIFICATION_PUSH_TYPE_ALERT);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_BADGE_NUMBER",MA_NOTIFICATION_LOCAL_BADGE_NUMBER);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_FIRE_DATE",MA_NOTIFICATION_LOCAL_FIRE_DATE);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_CONTENT_BODY",MA_NOTIFICATION_LOCAL_CONTENT_BODY);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_ALERT_ACTION",MA_NOTIFICATION_LOCAL_ALERT_ACTION);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_PLAY_SOUND",MA_NOTIFICATION_LOCAL_PLAY_SOUND);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_SOUND_PATH",MA_NOTIFICATION_LOCAL_SOUND_PATH);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_CONTENT_TITLE",MA_NOTIFICATION_LOCAL_CONTENT_TITLE);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_TICKER_TEXT",MA_NOTIFICATION_LOCAL_TICKER_TEXT);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_FLAG",MA_NOTIFICATION_LOCAL_FLAG);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_DISPLAY_FLAG",MA_NOTIFICATION_LOCAL_DISPLAY_FLAG);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_VIBRATE",MA_NOTIFICATION_LOCAL_VIBRATE);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_VIBRATE_DURATION",MA_NOTIFICATION_LOCAL_VIBRATE_DURATION);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_FLASH_LIGHTS",MA_NOTIFICATION_LOCAL_FLASH_LIGHTS);
 tolua_constant_string(tolua_S,"MA_NOTIFICATION_LOCAL_FLASH_LIGHTS_PATTERN",MA_NOTIFICATION_LOCAL_FLASH_LIGHTS_PATTERN);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_OK",MA_CAPTURE_RES_OK);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_FILE_INVALID_NAME",MA_CAPTURE_RES_FILE_INVALID_NAME);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_FILE_ALREADY_EXISTS",MA_CAPTURE_RES_FILE_ALREADY_EXISTS);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_INVALID_PROPERTY",MA_CAPTURE_RES_INVALID_PROPERTY);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_INVALID_PROPERTY_VALUE",MA_CAPTURE_RES_INVALID_PROPERTY_VALUE);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_INVALID_STRING_BUFFER_SIZE",MA_CAPTURE_RES_INVALID_STRING_BUFFER_SIZE);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_INVALID_ACTION",MA_CAPTURE_RES_INVALID_ACTION);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_INVALID_HANDLE",MA_CAPTURE_RES_INVALID_HANDLE);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_UNSUPPORTED",MA_CAPTURE_RES_UNSUPPORTED);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_CAMERA_NOT_AVAILABLE",MA_CAPTURE_RES_CAMERA_NOT_AVAILABLE);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_VIDEO_NOT_SUPPORTED",MA_CAPTURE_RES_VIDEO_NOT_SUPPORTED);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_PICTURE_NOT_SUPPORTED",MA_CAPTURE_RES_PICTURE_NOT_SUPPORTED);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_FLASH_NOT_SUPPORTED",MA_CAPTURE_RES_FLASH_NOT_SUPPORTED);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_MAX_DURATION_NOT_SUPPORTED",MA_CAPTURE_RES_MAX_DURATION_NOT_SUPPORTED);
 tolua_constant(tolua_S,"MA_CAPTURE_RES_PROPERTY_VALUE_UNDEFINED",MA_CAPTURE_RES_PROPERTY_VALUE_UNDEFINED);
 tolua_constant_string(tolua_S,"MA_CAPTURE_MAX_DURATION",MA_CAPTURE_MAX_DURATION);
 tolua_constant_string(tolua_S,"MA_CAPTURE_VIDEO_QUALITY",MA_CAPTURE_VIDEO_QUALITY);
 tolua_constant_string(tolua_S,"MA_CAPTURE_CAMERA_ROLL",MA_CAPTURE_CAMERA_ROLL);
 tolua_constant_string(tolua_S,"MA_CAPTURE_FLASH",MA_CAPTURE_FLASH);
 tolua_constant_string(tolua_S,"MA_CAPTURE_CAMERA_CONTROLS",MA_CAPTURE_CAMERA_CONTROLS);
 tolua_constant(tolua_S,"MA_CAPTURE_VIDEO_QUALITY_LOW",MA_CAPTURE_VIDEO_QUALITY_LOW);
 tolua_constant(tolua_S,"MA_CAPTURE_VIDEO_QUALITY_HIGH",MA_CAPTURE_VIDEO_QUALITY_HIGH);
 tolua_constant(tolua_S,"MA_CAPTURE_VIDEO_QUALITY_MEDIUM",MA_CAPTURE_VIDEO_QUALITY_MEDIUM);
 tolua_constant(tolua_S,"MA_CAPTURE_ACTION_RECORD_VIDEO",MA_CAPTURE_ACTION_RECORD_VIDEO);
 tolua_constant(tolua_S,"MA_CAPTURE_ACTION_STOP_RECORDING",MA_CAPTURE_ACTION_STOP_RECORDING);
 tolua_constant(tolua_S,"MA_CAPTURE_ACTION_TAKE_PICTURE",MA_CAPTURE_ACTION_TAKE_PICTURE);
 tolua_constant(tolua_S,"MA_CAPTURE_EVENT_TYPE_IMAGE",MA_CAPTURE_EVENT_TYPE_IMAGE);
 tolua_constant(tolua_S,"MA_CAPTURE_EVENT_TYPE_VIDEO",MA_CAPTURE_EVENT_TYPE_VIDEO);
 tolua_constant(tolua_S,"MA_CAPTURE_EVENT_TYPE_CANCEL",MA_CAPTURE_EVENT_TYPE_CANCEL);
 tolua_constant(tolua_S,"MA_CAPTURE_FLASH_AUTO",MA_CAPTURE_FLASH_AUTO);
 tolua_constant(tolua_S,"MA_CAPTURE_FLASH_ON",MA_CAPTURE_FLASH_ON);
 tolua_constant(tolua_S,"MA_CAPTURE_FLASH_OFF",MA_CAPTURE_FLASH_OFF);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_OK",MA_PURCHASE_RES_OK);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_UNAVAILABLE",MA_PURCHASE_RES_UNAVAILABLE);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_CONNECTION_ERROR",MA_PURCHASE_RES_CONNECTION_ERROR);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_OUT_OF_DATE",MA_PURCHASE_RES_OUT_OF_DATE);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_CLIENT_INVALID",MA_PURCHASE_RES_CLIENT_INVALID);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_NOT_ALLOWED",MA_PURCHASE_RES_NOT_ALLOWED);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_DISABLED",MA_PURCHASE_RES_DISABLED);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_INVALID_HANDLE",MA_PURCHASE_RES_INVALID_HANDLE);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_BUFFER_TOO_SMALL",MA_PURCHASE_RES_BUFFER_TOO_SMALL);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_RECEIPT_NOT_AVAILABLE",MA_PURCHASE_RES_RECEIPT_NOT_AVAILABLE);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_INVALID_FIELD_NAME",MA_PURCHASE_RES_INVALID_FIELD_NAME);
 tolua_constant(tolua_S,"MA_PURCHASE_RES_MALFORMED_PUBLIC_KEY",MA_PURCHASE_RES_MALFORMED_PUBLIC_KEY);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_INVALID_HANDLE",MA_PURCHASE_ERROR_INVALID_HANDLE);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_CONNECTION_FAILED",MA_PURCHASE_ERROR_CONNECTION_FAILED);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_CANNOT_PARSE_RECEIPT",MA_PURCHASE_ERROR_CANNOT_PARSE_RECEIPT);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_INVALID_PRODUCT",MA_PURCHASE_ERROR_INVALID_PRODUCT);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_INVALID_CLIENT",MA_PURCHASE_ERROR_INVALID_CLIENT);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_CANCELLED",MA_PURCHASE_ERROR_CANCELLED);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_NOT_ALLOWED",MA_PURCHASE_ERROR_NOT_ALLOWED);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_PUBLIC_KEY_NOT_SET",MA_PURCHASE_ERROR_PUBLIC_KEY_NOT_SET);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_UNKNOWN",MA_PURCHASE_ERROR_UNKNOWN);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_INVALID_QUANTITY",MA_PURCHASE_ERROR_INVALID_QUANTITY);
 tolua_constant(tolua_S,"MA_PURCHASE_ERROR_NO_RECEIPT",MA_PURCHASE_ERROR_NO_RECEIPT);
 tolua_constant(tolua_S,"MA_PURCHASE_EVENT_PRODUCT_CREATE",MA_PURCHASE_EVENT_PRODUCT_CREATE);
 tolua_constant(tolua_S,"MA_PURCHASE_EVENT_REQUEST",MA_PURCHASE_EVENT_REQUEST);
 tolua_constant(tolua_S,"MA_PURCHASE_EVENT_VERIFY_RECEIPT",MA_PURCHASE_EVENT_VERIFY_RECEIPT);
 tolua_constant(tolua_S,"MA_PURCHASE_EVENT_REFUNDED",MA_PURCHASE_EVENT_REFUNDED);
 tolua_constant(tolua_S,"MA_PURCHASE_EVENT_RESTORE",MA_PURCHASE_EVENT_RESTORE);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_PRODUCT_VALID",MA_PURCHASE_STATE_PRODUCT_VALID);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_PRODUCT_INVALID",MA_PURCHASE_STATE_PRODUCT_INVALID);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_DISABLED",MA_PURCHASE_STATE_DISABLED);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_DUPLICATE_HANDLE",MA_PURCHASE_STATE_DUPLICATE_HANDLE);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_FAILED",MA_PURCHASE_STATE_FAILED);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_IN_PROGRESS",MA_PURCHASE_STATE_IN_PROGRESS);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_COMPLETED",MA_PURCHASE_STATE_COMPLETED);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_RECEIPT_VALID",MA_PURCHASE_STATE_RECEIPT_VALID);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_RECEIPT_INVALID",MA_PURCHASE_STATE_RECEIPT_INVALID);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_RECEIPT_ERROR",MA_PURCHASE_STATE_RECEIPT_ERROR);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_RESTORE_ERROR",MA_PURCHASE_STATE_RESTORE_ERROR);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_PRODUCT_RESTORED",MA_PURCHASE_STATE_PRODUCT_RESTORED);
 tolua_constant(tolua_S,"MA_PURCHASE_STATE_PRODUCT_REFUNDED",MA_PURCHASE_STATE_PRODUCT_REFUNDED);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_QUANTITY",MA_PURCHASE_RECEIPT_QUANTITY);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_PRODUCT_ID",MA_PURCHASE_RECEIPT_PRODUCT_ID);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_TRANSACTION_ID",MA_PURCHASE_RECEIPT_TRANSACTION_ID);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_PURCHASE_DATE",MA_PURCHASE_RECEIPT_PURCHASE_DATE);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_ORIGINAL_TRANSACTION_ID",MA_PURCHASE_RECEIPT_ORIGINAL_TRANSACTION_ID);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_APP_ITEM_ID",MA_PURCHASE_RECEIPT_APP_ITEM_ID);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_VERSION_EXTERNAL_IDENTIFIER",MA_PURCHASE_RECEIPT_VERSION_EXTERNAL_IDENTIFIER);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_BID",MA_PURCHASE_RECEIPT_BID);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_BVRS",MA_PURCHASE_RECEIPT_BVRS);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_PRICE",MA_PURCHASE_RECEIPT_PRICE);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_TITLE",MA_PURCHASE_RECEIPT_TITLE);
 tolua_constant_string(tolua_S,"MA_PURCHASE_RECEIPT_DESCRIPTION",MA_PURCHASE_RECEIPT_DESCRIPTION);
 tolua_constant(tolua_S,"IOCTL_UNAVAILABLE",IOCTL_UNAVAILABLE);
 tolua_function(tolua_S,"maCheckInterfaceVersion",tolua_lua_maapi_mosync_maCheckInterfaceVersion00);
 tolua_function(tolua_S,"maExit",tolua_lua_maapi_mosync_maExit00);
 tolua_function(tolua_S,"maPanic",tolua_lua_maapi_mosync_maPanic00);
 tolua_function(tolua_S,"memset",tolua_lua_maapi_mosync_memset00);
 tolua_function(tolua_S,"memcpy",tolua_lua_maapi_mosync_memcpy00);
 tolua_function(tolua_S,"strcmp",tolua_lua_maapi_mosync_strcmp00);
 tolua_function(tolua_S,"strcpy",tolua_lua_maapi_mosync_strcpy00);
 tolua_function(tolua_S,"__adddf3",tolua_lua_maapi_mosync___adddf300);
 tolua_function(tolua_S,"__subdf3",tolua_lua_maapi_mosync___subdf300);
 tolua_function(tolua_S,"__muldf3",tolua_lua_maapi_mosync___muldf300);
 tolua_function(tolua_S,"__divdf3",tolua_lua_maapi_mosync___divdf300);
 tolua_function(tolua_S,"__negdf2",tolua_lua_maapi_mosync___negdf200);
 tolua_function(tolua_S,"__fixdfsi",tolua_lua_maapi_mosync___fixdfsi00);
 tolua_function(tolua_S,"__fixunsdfsi",tolua_lua_maapi_mosync___fixunsdfsi00);
 tolua_function(tolua_S,"__floatsidf",tolua_lua_maapi_mosync___floatsidf00);
 tolua_function(tolua_S,"__extendsfdf2",tolua_lua_maapi_mosync___extendsfdf200);
 tolua_function(tolua_S,"dcmp",tolua_lua_maapi_mosync_dcmp00);
 tolua_function(tolua_S,"__addsf3",tolua_lua_maapi_mosync___addsf300);
 tolua_function(tolua_S,"__subsf3",tolua_lua_maapi_mosync___subsf300);
 tolua_function(tolua_S,"__mulsf3",tolua_lua_maapi_mosync___mulsf300);
 tolua_function(tolua_S,"__divsf3",tolua_lua_maapi_mosync___divsf300);
 tolua_function(tolua_S,"__negsf2",tolua_lua_maapi_mosync___negsf200);
 tolua_function(tolua_S,"__fixsfsi",tolua_lua_maapi_mosync___fixsfsi00);
 tolua_function(tolua_S,"__fixunssfsi",tolua_lua_maapi_mosync___fixunssfsi00);
 tolua_function(tolua_S,"__floatsisf",tolua_lua_maapi_mosync___floatsisf00);
 tolua_function(tolua_S,"__truncdfsf2",tolua_lua_maapi_mosync___truncdfsf200);
 tolua_function(tolua_S,"fcmp",tolua_lua_maapi_mosync_fcmp00);
 tolua_function(tolua_S,"sin",tolua_lua_maapi_mosync_sin00);
 tolua_function(tolua_S,"cos",tolua_lua_maapi_mosync_cos00);
 tolua_function(tolua_S,"tan",tolua_lua_maapi_mosync_tan00);
 tolua_function(tolua_S,"sqrt",tolua_lua_maapi_mosync_sqrt00);
 tolua_function(tolua_S,"maSetColor",tolua_lua_maapi_mosync_maSetColor00);
 tolua_function(tolua_S,"maSetClipRect",tolua_lua_maapi_mosync_maSetClipRect00);
 tolua_function(tolua_S,"maGetClipRect",tolua_lua_maapi_mosync_maGetClipRect00);
 tolua_function(tolua_S,"maPlot",tolua_lua_maapi_mosync_maPlot00);
 tolua_function(tolua_S,"maLine",tolua_lua_maapi_mosync_maLine00);
 tolua_function(tolua_S,"maFillRect",tolua_lua_maapi_mosync_maFillRect00);
 tolua_function(tolua_S,"maFillTriangleStrip",tolua_lua_maapi_mosync_maFillTriangleStrip00);
 tolua_function(tolua_S,"maFillTriangleFan",tolua_lua_maapi_mosync_maFillTriangleFan00);
 tolua_function(tolua_S,"maGetTextSize",tolua_lua_maapi_mosync_maGetTextSize00);
 tolua_function(tolua_S,"maGetTextSizeW",tolua_lua_maapi_mosync_maGetTextSizeW00);
 tolua_function(tolua_S,"maDrawText",tolua_lua_maapi_mosync_maDrawText00);
 tolua_function(tolua_S,"maDrawTextW",tolua_lua_maapi_mosync_maDrawTextW00);
 tolua_function(tolua_S,"maUpdateScreen",tolua_lua_maapi_mosync_maUpdateScreen00);
 tolua_function(tolua_S,"maResetBacklight",tolua_lua_maapi_mosync_maResetBacklight00);
 tolua_function(tolua_S,"maGetScrSize",tolua_lua_maapi_mosync_maGetScrSize00);
 tolua_function(tolua_S,"maDrawImage",tolua_lua_maapi_mosync_maDrawImage00);
 tolua_function(tolua_S,"maDrawRGB",tolua_lua_maapi_mosync_maDrawRGB00);
 tolua_function(tolua_S,"maDrawImageRegion",tolua_lua_maapi_mosync_maDrawImageRegion00);
 tolua_function(tolua_S,"maGetImageSize",tolua_lua_maapi_mosync_maGetImageSize00);
 tolua_function(tolua_S,"maGetImageData",tolua_lua_maapi_mosync_maGetImageData00);
 tolua_function(tolua_S,"maSetDrawTarget",tolua_lua_maapi_mosync_maSetDrawTarget00);
 tolua_function(tolua_S,"maFindLabel",tolua_lua_maapi_mosync_maFindLabel00);
 tolua_function(tolua_S,"maCreateImageFromData",tolua_lua_maapi_mosync_maCreateImageFromData00);
 tolua_function(tolua_S,"maCreateImageRaw",tolua_lua_maapi_mosync_maCreateImageRaw00);
 tolua_function(tolua_S,"maCreateDrawableImage",tolua_lua_maapi_mosync_maCreateDrawableImage00);
 tolua_function(tolua_S,"maCreateData",tolua_lua_maapi_mosync_maCreateData00);
 tolua_function(tolua_S,"maCreatePlaceholder",tolua_lua_maapi_mosync_maCreatePlaceholder00);
 tolua_function(tolua_S,"maDestroyPlaceholder",tolua_lua_maapi_mosync_maDestroyPlaceholder00);
 tolua_function(tolua_S,"maDestroyObject",tolua_lua_maapi_mosync_maDestroyObject00);
 tolua_function(tolua_S,"maGetDataSize",tolua_lua_maapi_mosync_maGetDataSize00);
 tolua_function(tolua_S,"maReadData",tolua_lua_maapi_mosync_maReadData00);
 tolua_function(tolua_S,"maWriteData",tolua_lua_maapi_mosync_maWriteData00);
 tolua_function(tolua_S,"maCopyData",tolua_lua_maapi_mosync_maCopyData00);
 tolua_function(tolua_S,"maOpenStore",tolua_lua_maapi_mosync_maOpenStore00);
 tolua_function(tolua_S,"maWriteStore",tolua_lua_maapi_mosync_maWriteStore00);
 tolua_function(tolua_S,"maReadStore",tolua_lua_maapi_mosync_maReadStore00);
 tolua_function(tolua_S,"maCloseStore",tolua_lua_maapi_mosync_maCloseStore00);
 tolua_function(tolua_S,"maConnect",tolua_lua_maapi_mosync_maConnect00);
 tolua_function(tolua_S,"maConnClose",tolua_lua_maapi_mosync_maConnClose00);
 tolua_function(tolua_S,"maConnRead",tolua_lua_maapi_mosync_maConnRead00);
 tolua_function(tolua_S,"maConnWrite",tolua_lua_maapi_mosync_maConnWrite00);
 tolua_function(tolua_S,"maConnReadToData",tolua_lua_maapi_mosync_maConnReadToData00);
 tolua_function(tolua_S,"maConnWriteFromData",tolua_lua_maapi_mosync_maConnWriteFromData00);
 tolua_function(tolua_S,"maConnGetAddr",tolua_lua_maapi_mosync_maConnGetAddr00);
 tolua_function(tolua_S,"maHttpCreate",tolua_lua_maapi_mosync_maHttpCreate00);
 tolua_function(tolua_S,"maHttpSetRequestHeader",tolua_lua_maapi_mosync_maHttpSetRequestHeader00);
 tolua_function(tolua_S,"maHttpGetResponseHeader",tolua_lua_maapi_mosync_maHttpGetResponseHeader00);
 tolua_function(tolua_S,"maHttpFinish",tolua_lua_maapi_mosync_maHttpFinish00);
 tolua_function(tolua_S,"maLoadResources",tolua_lua_maapi_mosync_maLoadResources00);
 tolua_function(tolua_S,"maLoadResource",tolua_lua_maapi_mosync_maLoadResource00);
 tolua_function(tolua_S,"maCountResources",tolua_lua_maapi_mosync_maCountResources00);
 tolua_function(tolua_S,"maLoadProgram",tolua_lua_maapi_mosync_maLoadProgram00);
 tolua_function(tolua_S,"maGetKeys",tolua_lua_maapi_mosync_maGetKeys00);
 tolua_function(tolua_S,"maGetEvent",tolua_lua_maapi_mosync_maGetEvent00);
 tolua_function(tolua_S,"maWait",tolua_lua_maapi_mosync_maWait00);
 tolua_function(tolua_S,"maTime",tolua_lua_maapi_mosync_maTime00);
 tolua_function(tolua_S,"maLocalTime",tolua_lua_maapi_mosync_maLocalTime00);
 tolua_function(tolua_S,"maGetMilliSecondCount",tolua_lua_maapi_mosync_maGetMilliSecondCount00);
 tolua_function(tolua_S,"maFreeObjectMemory",tolua_lua_maapi_mosync_maFreeObjectMemory00);
 tolua_function(tolua_S,"maTotalObjectMemory",tolua_lua_maapi_mosync_maTotalObjectMemory00);
 tolua_function(tolua_S,"maVibrate",tolua_lua_maapi_mosync_maVibrate00);
 tolua_function(tolua_S,"maSoundPlay",tolua_lua_maapi_mosync_maSoundPlay00);
 tolua_function(tolua_S,"maSoundStop",tolua_lua_maapi_mosync_maSoundStop00);
 tolua_function(tolua_S,"maSoundIsPlaying",tolua_lua_maapi_mosync_maSoundIsPlaying00);
 tolua_function(tolua_S,"maSoundGetVolume",tolua_lua_maapi_mosync_maSoundGetVolume00);
 tolua_function(tolua_S,"maSoundSetVolume",tolua_lua_maapi_mosync_maSoundSetVolume00);
 tolua_function(tolua_S,"maExtensionFunctionInvoke",tolua_lua_maapi_mosync_maExtensionFunctionInvoke00);
 tolua_function(tolua_S,"maExtensionModuleLoad",tolua_lua_maapi_mosync_maExtensionModuleLoad00);
 tolua_function(tolua_S,"maExtensionFunctionLoad",tolua_lua_maapi_mosync_maExtensionFunctionLoad00);
 tolua_function(tolua_S,"maFontLoadDefault",tolua_lua_maapi_mosync_maFontLoadDefault00);
 tolua_function(tolua_S,"maFontSetCurrent",tolua_lua_maapi_mosync_maFontSetCurrent00);
 tolua_function(tolua_S,"maFontGetCount",tolua_lua_maapi_mosync_maFontGetCount00);
 tolua_function(tolua_S,"maFontGetName",tolua_lua_maapi_mosync_maFontGetName00);
 tolua_function(tolua_S,"maFontLoadWithName",tolua_lua_maapi_mosync_maFontLoadWithName00);
 tolua_function(tolua_S,"maFontDelete",tolua_lua_maapi_mosync_maFontDelete00);
 tolua_function(tolua_S,"maReportCallStack",tolua_lua_maapi_mosync_maReportCallStack00);
 tolua_function(tolua_S,"maDumpCallStackEx",tolua_lua_maapi_mosync_maDumpCallStackEx00);
 tolua_function(tolua_S,"maProtectMemory",tolua_lua_maapi_mosync_maProtectMemory00);
 tolua_function(tolua_S,"maUnprotectMemory",tolua_lua_maapi_mosync_maUnprotectMemory00);
 tolua_function(tolua_S,"maSetMemoryProtection",tolua_lua_maapi_mosync_maSetMemoryProtection00);
 tolua_function(tolua_S,"maGetMemoryProtection",tolua_lua_maapi_mosync_maGetMemoryProtection00);
 tolua_function(tolua_S,"maGetBatteryCharge",tolua_lua_maapi_mosync_maGetBatteryCharge00);
 tolua_function(tolua_S,"maLockKeypad",tolua_lua_maapi_mosync_maLockKeypad00);
 tolua_function(tolua_S,"maUnlockKeypad",tolua_lua_maapi_mosync_maUnlockKeypad00);
 tolua_function(tolua_S,"maKeypadIsLocked",tolua_lua_maapi_mosync_maKeypadIsLocked00);
 tolua_function(tolua_S,"maWriteLog",tolua_lua_maapi_mosync_maWriteLog00);
 tolua_function(tolua_S,"maBtStartDeviceDiscovery",tolua_lua_maapi_mosync_maBtStartDeviceDiscovery00);
 tolua_function(tolua_S,"maBtGetNewDevice",tolua_lua_maapi_mosync_maBtGetNewDevice00);
 tolua_function(tolua_S,"maBtStartServiceDiscovery",tolua_lua_maapi_mosync_maBtStartServiceDiscovery00);
 tolua_function(tolua_S,"maBtGetNextServiceSize",tolua_lua_maapi_mosync_maBtGetNextServiceSize00);
 tolua_function(tolua_S,"maBtGetNewService",tolua_lua_maapi_mosync_maBtGetNewService00);
 tolua_function(tolua_S,"maBtCancelDiscovery",tolua_lua_maapi_mosync_maBtCancelDiscovery00);
 tolua_function(tolua_S,"maLocationStart",tolua_lua_maapi_mosync_maLocationStart00);
 tolua_function(tolua_S,"maLocationStop",tolua_lua_maapi_mosync_maLocationStop00);
 tolua_function(tolua_S,"maPlatformRequest",tolua_lua_maapi_mosync_maPlatformRequest00);
 tolua_function(tolua_S,"maFileOpen",tolua_lua_maapi_mosync_maFileOpen00);
 tolua_function(tolua_S,"maFileExists",tolua_lua_maapi_mosync_maFileExists00);
 tolua_function(tolua_S,"maFileClose",tolua_lua_maapi_mosync_maFileClose00);
 tolua_function(tolua_S,"maFileCreate",tolua_lua_maapi_mosync_maFileCreate00);
 tolua_function(tolua_S,"maFileDelete",tolua_lua_maapi_mosync_maFileDelete00);
 tolua_function(tolua_S,"maFileSize",tolua_lua_maapi_mosync_maFileSize00);
 tolua_function(tolua_S,"maFileAvailableSpace",tolua_lua_maapi_mosync_maFileAvailableSpace00);
 tolua_function(tolua_S,"maFileTotalSpace",tolua_lua_maapi_mosync_maFileTotalSpace00);
 tolua_function(tolua_S,"maFileDate",tolua_lua_maapi_mosync_maFileDate00);
 tolua_function(tolua_S,"maFileRename",tolua_lua_maapi_mosync_maFileRename00);
 tolua_function(tolua_S,"maFileTruncate",tolua_lua_maapi_mosync_maFileTruncate00);
 tolua_function(tolua_S,"maFileWrite",tolua_lua_maapi_mosync_maFileWrite00);
 tolua_function(tolua_S,"maFileWriteFromData",tolua_lua_maapi_mosync_maFileWriteFromData00);
 tolua_function(tolua_S,"maFileRead",tolua_lua_maapi_mosync_maFileRead00);
 tolua_function(tolua_S,"maFileReadToData",tolua_lua_maapi_mosync_maFileReadToData00);
 tolua_function(tolua_S,"maFileTell",tolua_lua_maapi_mosync_maFileTell00);
 tolua_function(tolua_S,"maFileSeek",tolua_lua_maapi_mosync_maFileSeek00);
 tolua_function(tolua_S,"maFileListStart",tolua_lua_maapi_mosync_maFileListStart00);
 tolua_function(tolua_S,"maFileListNext",tolua_lua_maapi_mosync_maFileListNext00);
 tolua_function(tolua_S,"maFileListClose",tolua_lua_maapi_mosync_maFileListClose00);
 tolua_function(tolua_S,"maSendTextSMS",tolua_lua_maapi_mosync_maSendTextSMS00);
 tolua_function(tolua_S,"maFrameBufferGetInfo",tolua_lua_maapi_mosync_maFrameBufferGetInfo00);
 tolua_function(tolua_S,"maFrameBufferInit",tolua_lua_maapi_mosync_maFrameBufferInit00);
 tolua_function(tolua_S,"maFrameBufferClose",tolua_lua_maapi_mosync_maFrameBufferClose00);
 tolua_function(tolua_S,"maAccept",tolua_lua_maapi_mosync_maAccept00);
 tolua_function(tolua_S,"maSendToBackground",tolua_lua_maapi_mosync_maSendToBackground00);
 tolua_function(tolua_S,"maBringToForeground",tolua_lua_maapi_mosync_maBringToForeground00);
 tolua_function(tolua_S,"maGetSystemProperty",tolua_lua_maapi_mosync_maGetSystemProperty00);
 tolua_function(tolua_S,"maIapSave",tolua_lua_maapi_mosync_maIapSave00);
 tolua_function(tolua_S,"maIapReset",tolua_lua_maapi_mosync_maIapReset00);
 tolua_function(tolua_S,"maIapShutdown",tolua_lua_maapi_mosync_maIapShutdown00);
 tolua_function(tolua_S,"maNetworkStatus",tolua_lua_maapi_mosync_maNetworkStatus00);
 tolua_function(tolua_S,"maIapSetMethod",tolua_lua_maapi_mosync_maIapSetMethod00);
 tolua_function(tolua_S,"maIapSetFilter",tolua_lua_maapi_mosync_maIapSetFilter00);
 tolua_function(tolua_S,"maCameraFormatNumber",tolua_lua_maapi_mosync_maCameraFormatNumber00);
 tolua_function(tolua_S,"maCameraFormat",tolua_lua_maapi_mosync_maCameraFormat00);
 tolua_function(tolua_S,"maCameraStart",tolua_lua_maapi_mosync_maCameraStart00);
 tolua_function(tolua_S,"maCameraStop",tolua_lua_maapi_mosync_maCameraStop00);
 tolua_function(tolua_S,"maCameraSetPreview",tolua_lua_maapi_mosync_maCameraSetPreview00);
 tolua_function(tolua_S,"maCameraSelect",tolua_lua_maapi_mosync_maCameraSelect00);
 tolua_function(tolua_S,"maCameraNumber",tolua_lua_maapi_mosync_maCameraNumber00);
 tolua_function(tolua_S,"maCameraSnapshot",tolua_lua_maapi_mosync_maCameraSnapshot00);
 tolua_function(tolua_S,"maCameraRecord",tolua_lua_maapi_mosync_maCameraRecord00);
 tolua_function(tolua_S,"maCameraSetProperty",tolua_lua_maapi_mosync_maCameraSetProperty00);
 tolua_function(tolua_S,"maCameraGetProperty",tolua_lua_maapi_mosync_maCameraGetProperty00);
 tolua_function(tolua_S,"maShowVirtualKeyboard",tolua_lua_maapi_mosync_maShowVirtualKeyboard00);
 tolua_function(tolua_S,"maTextBox",tolua_lua_maapi_mosync_maTextBox00);
 tolua_function(tolua_S,"maKeyCaptureStart",tolua_lua_maapi_mosync_maKeyCaptureStart00);
 tolua_function(tolua_S,"maKeyCaptureStop",tolua_lua_maapi_mosync_maKeyCaptureStop00);
 tolua_function(tolua_S,"maHomeScreenEventsOn",tolua_lua_maapi_mosync_maHomeScreenEventsOn00);
 tolua_function(tolua_S,"maHomeScreenEventsOff",tolua_lua_maapi_mosync_maHomeScreenEventsOff00);
 tolua_function(tolua_S,"maHomeScreenShortcutAdd",tolua_lua_maapi_mosync_maHomeScreenShortcutAdd00);
 tolua_function(tolua_S,"maHomeScreenShortcutRemove",tolua_lua_maapi_mosync_maHomeScreenShortcutRemove00);
 tolua_function(tolua_S,"maNotificationAdd",tolua_lua_maapi_mosync_maNotificationAdd00);
 tolua_function(tolua_S,"maNotificationRemove",tolua_lua_maapi_mosync_maNotificationRemove00);
 tolua_function(tolua_S,"maScreenSetOrientation",tolua_lua_maapi_mosync_maScreenSetOrientation00);
 tolua_function(tolua_S,"maScreenSetFullscreen",tolua_lua_maapi_mosync_maScreenSetFullscreen00);
 tolua_function(tolua_S,"maAutostartOn",tolua_lua_maapi_mosync_maAutostartOn00);
 tolua_function(tolua_S,"maAutostartOff",tolua_lua_maapi_mosync_maAutostartOff00);
 tolua_function(tolua_S,"maScreenSetSupportedOrientations",tolua_lua_maapi_mosync_maScreenSetSupportedOrientations00);
 tolua_function(tolua_S,"maScreenGetSupportedOrientations",tolua_lua_maapi_mosync_maScreenGetSupportedOrientations00);
 tolua_function(tolua_S,"maScreenGetCurrentOrientation",tolua_lua_maapi_mosync_maScreenGetCurrentOrientation00);
 tolua_function(tolua_S,"maScreenStateEventsOn",tolua_lua_maapi_mosync_maScreenStateEventsOn00);
 tolua_function(tolua_S,"maScreenStateEventsOff",tolua_lua_maapi_mosync_maScreenStateEventsOff00);
 tolua_function(tolua_S,"maWakeLock",tolua_lua_maapi_mosync_maWakeLock00);
 tolua_function(tolua_S,"maReportResourceInformation",tolua_lua_maapi_mosync_maReportResourceInformation00);
 tolua_function(tolua_S,"maMessageBox",tolua_lua_maapi_mosync_maMessageBox00);
 tolua_function(tolua_S,"maAlert",tolua_lua_maapi_mosync_maAlert00);
 tolua_function(tolua_S,"maImagePickerOpen",tolua_lua_maapi_mosync_maImagePickerOpen00);
 tolua_function(tolua_S,"maOptionsBox",tolua_lua_maapi_mosync_maOptionsBox00);
 tolua_function(tolua_S,"maSensorStart",tolua_lua_maapi_mosync_maSensorStart00);
 tolua_function(tolua_S,"maSensorStop",tolua_lua_maapi_mosync_maSensorStop00);
 tolua_function(tolua_S,"maNFCStart",tolua_lua_maapi_mosync_maNFCStart00);
 tolua_function(tolua_S,"maNFCStop",tolua_lua_maapi_mosync_maNFCStop00);
 tolua_function(tolua_S,"maNFCReadTag",tolua_lua_maapi_mosync_maNFCReadTag00);
 tolua_function(tolua_S,"maNFCDestroyTag",tolua_lua_maapi_mosync_maNFCDestroyTag00);
 tolua_function(tolua_S,"maNFCConnectTag",tolua_lua_maapi_mosync_maNFCConnectTag00);
 tolua_function(tolua_S,"maNFCCloseTag",tolua_lua_maapi_mosync_maNFCCloseTag00);
 tolua_function(tolua_S,"maNFCIsType",tolua_lua_maapi_mosync_maNFCIsType00);
 tolua_function(tolua_S,"maNFCGetTypedTag",tolua_lua_maapi_mosync_maNFCGetTypedTag00);
 tolua_function(tolua_S,"maNFCBatchStart",tolua_lua_maapi_mosync_maNFCBatchStart00);
 tolua_function(tolua_S,"maNFCBatchCommit",tolua_lua_maapi_mosync_maNFCBatchCommit00);
 tolua_function(tolua_S,"maNFCBatchRollback",tolua_lua_maapi_mosync_maNFCBatchRollback00);
 tolua_function(tolua_S,"maNFCTransceive",tolua_lua_maapi_mosync_maNFCTransceive00);
 tolua_function(tolua_S,"maNFCSetReadOnly",tolua_lua_maapi_mosync_maNFCSetReadOnly00);
 tolua_function(tolua_S,"maNFCIsReadOnly",tolua_lua_maapi_mosync_maNFCIsReadOnly00);
 tolua_function(tolua_S,"maNFCGetSize",tolua_lua_maapi_mosync_maNFCGetSize00);
 tolua_function(tolua_S,"maNFCReadNDEFMessage",tolua_lua_maapi_mosync_maNFCReadNDEFMessage00);
 tolua_function(tolua_S,"maNFCWriteNDEFMessage",tolua_lua_maapi_mosync_maNFCWriteNDEFMessage00);
 tolua_function(tolua_S,"maNFCCreateNDEFMessage",tolua_lua_maapi_mosync_maNFCCreateNDEFMessage00);
 tolua_function(tolua_S,"maNFCGetNDEFMessage",tolua_lua_maapi_mosync_maNFCGetNDEFMessage00);
 tolua_function(tolua_S,"maNFCGetNDEFRecord",tolua_lua_maapi_mosync_maNFCGetNDEFRecord00);
 tolua_function(tolua_S,"maNFCGetNDEFRecordCount",tolua_lua_maapi_mosync_maNFCGetNDEFRecordCount00);
 tolua_function(tolua_S,"maNFCGetNDEFId",tolua_lua_maapi_mosync_maNFCGetNDEFId00);
 tolua_function(tolua_S,"maNFCGetNDEFPayload",tolua_lua_maapi_mosync_maNFCGetNDEFPayload00);
 tolua_function(tolua_S,"maNFCGetNDEFTnf",tolua_lua_maapi_mosync_maNFCGetNDEFTnf00);
 tolua_function(tolua_S,"maNFCGetNDEFType",tolua_lua_maapi_mosync_maNFCGetNDEFType00);
 tolua_function(tolua_S,"maNFCSetNDEFId",tolua_lua_maapi_mosync_maNFCSetNDEFId00);
 tolua_function(tolua_S,"maNFCSetNDEFPayload",tolua_lua_maapi_mosync_maNFCSetNDEFPayload00);
 tolua_function(tolua_S,"maNFCSetNDEFTnf",tolua_lua_maapi_mosync_maNFCSetNDEFTnf00);
 tolua_function(tolua_S,"maNFCSetNDEFType",tolua_lua_maapi_mosync_maNFCSetNDEFType00);
 tolua_function(tolua_S,"maNFCAuthenticateMifareSector",tolua_lua_maapi_mosync_maNFCAuthenticateMifareSector00);
 tolua_function(tolua_S,"maNFCGetMifareSectorCount",tolua_lua_maapi_mosync_maNFCGetMifareSectorCount00);
 tolua_function(tolua_S,"maNFCGetMifareBlockCountInSector",tolua_lua_maapi_mosync_maNFCGetMifareBlockCountInSector00);
 tolua_function(tolua_S,"maNFCMifareSectorToBlock",tolua_lua_maapi_mosync_maNFCMifareSectorToBlock00);
 tolua_function(tolua_S,"maNFCReadMifareBlocks",tolua_lua_maapi_mosync_maNFCReadMifareBlocks00);
 tolua_function(tolua_S,"maNFCWriteMifareBlocks",tolua_lua_maapi_mosync_maNFCWriteMifareBlocks00);
 tolua_function(tolua_S,"maNFCReadMifarePages",tolua_lua_maapi_mosync_maNFCReadMifarePages00);
 tolua_function(tolua_S,"maNFCWriteMifarePages",tolua_lua_maapi_mosync_maNFCWriteMifarePages00);
 tolua_function(tolua_S,"maDBOpen",tolua_lua_maapi_mosync_maDBOpen00);
 tolua_function(tolua_S,"maDBClose",tolua_lua_maapi_mosync_maDBClose00);
 tolua_function(tolua_S,"maDBExecSQL",tolua_lua_maapi_mosync_maDBExecSQL00);
 tolua_function(tolua_S,"maDBExecSQLParams",tolua_lua_maapi_mosync_maDBExecSQLParams00);
 tolua_function(tolua_S,"maDBCursorDestroy",tolua_lua_maapi_mosync_maDBCursorDestroy00);
 tolua_function(tolua_S,"maDBCursorNext",tolua_lua_maapi_mosync_maDBCursorNext00);
 tolua_function(tolua_S,"maDBCursorGetColumnData",tolua_lua_maapi_mosync_maDBCursorGetColumnData00);
 tolua_function(tolua_S,"maDBCursorGetColumnText",tolua_lua_maapi_mosync_maDBCursorGetColumnText00);
 tolua_function(tolua_S,"maDBCursorGetColumnInt",tolua_lua_maapi_mosync_maDBCursorGetColumnInt00);
 tolua_function(tolua_S,"maDBCursorGetColumnDouble",tolua_lua_maapi_mosync_maDBCursorGetColumnDouble00);
 tolua_function(tolua_S,"maAudioDataCreateFromResource",tolua_lua_maapi_mosync_maAudioDataCreateFromResource00);
 tolua_function(tolua_S,"maAudioDataCreateFromURL",tolua_lua_maapi_mosync_maAudioDataCreateFromURL00);
 tolua_function(tolua_S,"maAudioDataDestroy",tolua_lua_maapi_mosync_maAudioDataDestroy00);
 tolua_function(tolua_S,"maAudioInstanceCreate",tolua_lua_maapi_mosync_maAudioInstanceCreate00);
 tolua_function(tolua_S,"maAudioInstanceCreateDynamic",tolua_lua_maapi_mosync_maAudioInstanceCreateDynamic00);
 tolua_function(tolua_S,"maAudioSubmitBuffer",tolua_lua_maapi_mosync_maAudioSubmitBuffer00);
 tolua_function(tolua_S,"maAudioGetPendingBufferCount",tolua_lua_maapi_mosync_maAudioGetPendingBufferCount00);
 tolua_function(tolua_S,"maAudioInstanceDestroy",tolua_lua_maapi_mosync_maAudioInstanceDestroy00);
 tolua_function(tolua_S,"maAudioGetLength",tolua_lua_maapi_mosync_maAudioGetLength00);
 tolua_function(tolua_S,"maAudioSetNumberOfLoops",tolua_lua_maapi_mosync_maAudioSetNumberOfLoops00);
 tolua_function(tolua_S,"maAudioPrepare",tolua_lua_maapi_mosync_maAudioPrepare00);
 tolua_function(tolua_S,"maAudioPlay",tolua_lua_maapi_mosync_maAudioPlay00);
 tolua_function(tolua_S,"maAudioSetPosition",tolua_lua_maapi_mosync_maAudioSetPosition00);
 tolua_function(tolua_S,"maAudioGetPosition",tolua_lua_maapi_mosync_maAudioGetPosition00);
 tolua_function(tolua_S,"maAudioSetVolume",tolua_lua_maapi_mosync_maAudioSetVolume00);
 tolua_function(tolua_S,"maAudioPause",tolua_lua_maapi_mosync_maAudioPause00);
 tolua_function(tolua_S,"maAudioStop",tolua_lua_maapi_mosync_maAudioStop00);
 tolua_function(tolua_S,"maSyscallPanicsEnable",tolua_lua_maapi_mosync_maSyscallPanicsEnable00);
 tolua_function(tolua_S,"maSyscallPanicsDisable",tolua_lua_maapi_mosync_maSyscallPanicsDisable00);
 tolua_function(tolua_S,"maAdsBannerCreate",tolua_lua_maapi_mosync_maAdsBannerCreate00);
 tolua_function(tolua_S,"maAdsBannerDestroy",tolua_lua_maapi_mosync_maAdsBannerDestroy00);
 tolua_function(tolua_S,"maAdsAddBannerToLayout",tolua_lua_maapi_mosync_maAdsAddBannerToLayout00);
 tolua_function(tolua_S,"maAdsRemoveBannerFromLayout",tolua_lua_maapi_mosync_maAdsRemoveBannerFromLayout00);
 tolua_function(tolua_S,"maAdsBannerSetProperty",tolua_lua_maapi_mosync_maAdsBannerSetProperty00);
 tolua_function(tolua_S,"maAdsBannerGetProperty",tolua_lua_maapi_mosync_maAdsBannerGetProperty00);
 tolua_function(tolua_S,"maNotificationLocalCreate",tolua_lua_maapi_mosync_maNotificationLocalCreate00);
 tolua_function(tolua_S,"maNotificationLocalDestroy",tolua_lua_maapi_mosync_maNotificationLocalDestroy00);
 tolua_function(tolua_S,"maNotificationLocalSetProperty",tolua_lua_maapi_mosync_maNotificationLocalSetProperty00);
 tolua_function(tolua_S,"maNotificationLocalGetProperty",tolua_lua_maapi_mosync_maNotificationLocalGetProperty00);
 tolua_function(tolua_S,"maNotificationLocalSchedule",tolua_lua_maapi_mosync_maNotificationLocalSchedule00);
 tolua_function(tolua_S,"maNotificationLocalUnschedule",tolua_lua_maapi_mosync_maNotificationLocalUnschedule00);
 tolua_function(tolua_S,"maNotificationPushRegister",tolua_lua_maapi_mosync_maNotificationPushRegister00);
 tolua_function(tolua_S,"maNotificationPushUnregister",tolua_lua_maapi_mosync_maNotificationPushUnregister00);
 tolua_function(tolua_S,"maNotificationPushGetRegistration",tolua_lua_maapi_mosync_maNotificationPushGetRegistration00);
 tolua_function(tolua_S,"maNotificationPushGetData",tolua_lua_maapi_mosync_maNotificationPushGetData00);
 tolua_function(tolua_S,"maNotificationPushDestroy",tolua_lua_maapi_mosync_maNotificationPushDestroy00);
 tolua_function(tolua_S,"maNotificationSetIconBadge",tolua_lua_maapi_mosync_maNotificationSetIconBadge00);
 tolua_function(tolua_S,"maNotificationGetIconBadge",tolua_lua_maapi_mosync_maNotificationGetIconBadge00);
 tolua_function(tolua_S,"maNotificationPushSetTickerText",tolua_lua_maapi_mosync_maNotificationPushSetTickerText00);
 tolua_function(tolua_S,"maNotificationPushSetMessageTitle",tolua_lua_maapi_mosync_maNotificationPushSetMessageTitle00);
 tolua_function(tolua_S,"maNotificationPushSetDisplayFlag",tolua_lua_maapi_mosync_maNotificationPushSetDisplayFlag00);
 tolua_function(tolua_S,"maCaptureSetProperty",tolua_lua_maapi_mosync_maCaptureSetProperty00);
 tolua_function(tolua_S,"maCaptureGetProperty",tolua_lua_maapi_mosync_maCaptureGetProperty00);
 tolua_function(tolua_S,"maCaptureAction",tolua_lua_maapi_mosync_maCaptureAction00);
 tolua_function(tolua_S,"maCaptureWriteImage",tolua_lua_maapi_mosync_maCaptureWriteImage00);
 tolua_function(tolua_S,"maCaptureGetImagePath",tolua_lua_maapi_mosync_maCaptureGetImagePath00);
 tolua_function(tolua_S,"maCaptureGetVideoPath",tolua_lua_maapi_mosync_maCaptureGetVideoPath00);
 tolua_function(tolua_S,"maCaptureDestroyData",tolua_lua_maapi_mosync_maCaptureDestroyData00);
 tolua_function(tolua_S,"maPurchaseSupported",tolua_lua_maapi_mosync_maPurchaseSupported00);
 tolua_function(tolua_S,"maPurchaseCreate",tolua_lua_maapi_mosync_maPurchaseCreate00);
 tolua_function(tolua_S,"maPurchaseSetPublicKey",tolua_lua_maapi_mosync_maPurchaseSetPublicKey00);
 tolua_function(tolua_S,"maPurchaseRequest",tolua_lua_maapi_mosync_maPurchaseRequest00);
 tolua_function(tolua_S,"maPurchaseVerifyReceipt",tolua_lua_maapi_mosync_maPurchaseVerifyReceipt00);
 tolua_function(tolua_S,"maPurchaseGetField",tolua_lua_maapi_mosync_maPurchaseGetField00);
 tolua_function(tolua_S,"maPurchaseSetStoreURL",tolua_lua_maapi_mosync_maPurchaseSetStoreURL00);
 tolua_function(tolua_S,"maPurchaseGetName",tolua_lua_maapi_mosync_maPurchaseGetName00);
 tolua_function(tolua_S,"maPurchaseRestoreTransactions",tolua_lua_maapi_mosync_maPurchaseRestoreTransactions00);
 tolua_function(tolua_S,"maPurchaseDestroy",tolua_lua_maapi_mosync_maPurchaseDestroy00);
 tolua_constant(tolua_S,"MA_GL_TEX_IMAGE_2D_OK",MA_GL_TEX_IMAGE_2D_OK);
 tolua_constant(tolua_S,"MA_GL_TEX_IMAGE_2D_INVALID_IMAGE",MA_GL_TEX_IMAGE_2D_INVALID_IMAGE);
 tolua_constant(tolua_S,"MA_GL_API_GL2",MA_GL_API_GL2);
 tolua_constant(tolua_S,"MA_GL_API_GL1",MA_GL_API_GL1);
 tolua_constant(tolua_S,"MA_GL_INIT_RES_OK",MA_GL_INIT_RES_OK);
 tolua_constant(tolua_S,"MA_GL_INIT_RES_UNAVAILABLE_API",MA_GL_INIT_RES_UNAVAILABLE_API);
 tolua_constant(tolua_S,"MA_GL_INIT_RES_ERROR",MA_GL_INIT_RES_ERROR);
 tolua_function(tolua_S,"maOpenGLInitFullscreen",tolua_lua_maapi_mosync_maOpenGLInitFullscreen00);
 tolua_function(tolua_S,"maOpenGLCloseFullscreen",tolua_lua_maapi_mosync_maOpenGLCloseFullscreen00);
 tolua_function(tolua_S,"maOpenGLTexImage2D",tolua_lua_maapi_mosync_maOpenGLTexImage2D00);
 tolua_function(tolua_S,"maOpenGLTexSubImage2D",tolua_lua_maapi_mosync_maOpenGLTexSubImage2D00);
 tolua_function(tolua_S,"glActiveTexture",tolua_lua_maapi_mosync_glActiveTexture00);
 tolua_function(tolua_S,"glBindBuffer",tolua_lua_maapi_mosync_glBindBuffer00);
 tolua_function(tolua_S,"glBindTexture",tolua_lua_maapi_mosync_glBindTexture00);
 tolua_function(tolua_S,"glBlendFunc",tolua_lua_maapi_mosync_glBlendFunc00);
 tolua_function(tolua_S,"glBufferData",tolua_lua_maapi_mosync_glBufferData00);
 tolua_function(tolua_S,"glBufferSubData",tolua_lua_maapi_mosync_glBufferSubData00);
 tolua_function(tolua_S,"glClear",tolua_lua_maapi_mosync_glClear00);
 tolua_function(tolua_S,"glClearColor",tolua_lua_maapi_mosync_glClearColor00);
 tolua_function(tolua_S,"glClearDepthf",tolua_lua_maapi_mosync_glClearDepthf00);
 tolua_function(tolua_S,"glClearStencil",tolua_lua_maapi_mosync_glClearStencil00);
 tolua_function(tolua_S,"glColorMask",tolua_lua_maapi_mosync_glColorMask00);
 tolua_function(tolua_S,"glCompressedTexImage2D",tolua_lua_maapi_mosync_glCompressedTexImage2D00);
 tolua_function(tolua_S,"glCompressedTexSubImage2D",tolua_lua_maapi_mosync_glCompressedTexSubImage2D00);
 tolua_function(tolua_S,"glCopyTexImage2D",tolua_lua_maapi_mosync_glCopyTexImage2D00);
 tolua_function(tolua_S,"glCopyTexSubImage2D",tolua_lua_maapi_mosync_glCopyTexSubImage2D00);
 tolua_function(tolua_S,"glCullFace",tolua_lua_maapi_mosync_glCullFace00);
 tolua_function(tolua_S,"glDeleteBuffers",tolua_lua_maapi_mosync_glDeleteBuffers00);
 tolua_function(tolua_S,"glDeleteTextures",tolua_lua_maapi_mosync_glDeleteTextures00);
 tolua_function(tolua_S,"glDepthFunc",tolua_lua_maapi_mosync_glDepthFunc00);
 tolua_function(tolua_S,"glDepthMask",tolua_lua_maapi_mosync_glDepthMask00);
 tolua_function(tolua_S,"glDepthRangef",tolua_lua_maapi_mosync_glDepthRangef00);
 tolua_function(tolua_S,"glDisable",tolua_lua_maapi_mosync_glDisable00);
 tolua_function(tolua_S,"glDrawArrays",tolua_lua_maapi_mosync_glDrawArrays00);
 tolua_function(tolua_S,"glDrawElements",tolua_lua_maapi_mosync_glDrawElements00);
 tolua_function(tolua_S,"glEnable",tolua_lua_maapi_mosync_glEnable00);
 tolua_function(tolua_S,"glFinish",tolua_lua_maapi_mosync_glFinish00);
 tolua_function(tolua_S,"glFlush",tolua_lua_maapi_mosync_glFlush00);
 tolua_function(tolua_S,"glFrontFace",tolua_lua_maapi_mosync_glFrontFace00);
 tolua_function(tolua_S,"glGenBuffers",tolua_lua_maapi_mosync_glGenBuffers00);
 tolua_function(tolua_S,"glGenTextures",tolua_lua_maapi_mosync_glGenTextures00);
 tolua_function(tolua_S,"glGetBooleanv",tolua_lua_maapi_mosync_glGetBooleanv00);
 tolua_function(tolua_S,"glGetBufferParameteriv",tolua_lua_maapi_mosync_glGetBufferParameteriv00);
 tolua_function(tolua_S,"glGetError",tolua_lua_maapi_mosync_glGetError00);
 tolua_function(tolua_S,"glGetFloatv",tolua_lua_maapi_mosync_glGetFloatv00);
 tolua_function(tolua_S,"glGetIntegerv",tolua_lua_maapi_mosync_glGetIntegerv00);
 tolua_function(tolua_S,"glGetStringHandle",tolua_lua_maapi_mosync_glGetStringHandle00);
 tolua_function(tolua_S,"glGetTexParameterfv",tolua_lua_maapi_mosync_glGetTexParameterfv00);
 tolua_function(tolua_S,"glGetTexParameteriv",tolua_lua_maapi_mosync_glGetTexParameteriv00);
 tolua_function(tolua_S,"glHint",tolua_lua_maapi_mosync_glHint00);
 tolua_function(tolua_S,"glIsBuffer",tolua_lua_maapi_mosync_glIsBuffer00);
 tolua_function(tolua_S,"glIsEnabled",tolua_lua_maapi_mosync_glIsEnabled00);
 tolua_function(tolua_S,"glIsTexture",tolua_lua_maapi_mosync_glIsTexture00);
 tolua_function(tolua_S,"glLineWidth",tolua_lua_maapi_mosync_glLineWidth00);
 tolua_function(tolua_S,"glPixelStorei",tolua_lua_maapi_mosync_glPixelStorei00);
 tolua_function(tolua_S,"glPolygonOffset",tolua_lua_maapi_mosync_glPolygonOffset00);
 tolua_function(tolua_S,"glReadPixels",tolua_lua_maapi_mosync_glReadPixels00);
 tolua_function(tolua_S,"glSampleCoverage",tolua_lua_maapi_mosync_glSampleCoverage00);
 tolua_function(tolua_S,"glScissor",tolua_lua_maapi_mosync_glScissor00);
 tolua_function(tolua_S,"glStencilFunc",tolua_lua_maapi_mosync_glStencilFunc00);
 tolua_function(tolua_S,"glStencilMask",tolua_lua_maapi_mosync_glStencilMask00);
 tolua_function(tolua_S,"glStencilOp",tolua_lua_maapi_mosync_glStencilOp00);
 tolua_function(tolua_S,"glTexImage2D",tolua_lua_maapi_mosync_glTexImage2D00);
 tolua_function(tolua_S,"glTexParameterf",tolua_lua_maapi_mosync_glTexParameterf00);
 tolua_function(tolua_S,"glTexParameterfv",tolua_lua_maapi_mosync_glTexParameterfv00);
 tolua_function(tolua_S,"glTexParameteri",tolua_lua_maapi_mosync_glTexParameteri00);
 tolua_function(tolua_S,"glTexParameteriv",tolua_lua_maapi_mosync_glTexParameteriv00);
 tolua_function(tolua_S,"glTexSubImage2D",tolua_lua_maapi_mosync_glTexSubImage2D00);
 tolua_function(tolua_S,"glViewport",tolua_lua_maapi_mosync_glViewport00);
 tolua_constant(tolua_S,"MAW_EVENT_POINTER_PRESSED",MAW_EVENT_POINTER_PRESSED);
 tolua_constant(tolua_S,"MAW_EVENT_POINTER_RELEASED",MAW_EVENT_POINTER_RELEASED);
 tolua_constant(tolua_S,"MAW_EVENT_CONTENT_LOADED",MAW_EVENT_CONTENT_LOADED);
 tolua_constant(tolua_S,"MAW_EVENT_CLICKED",MAW_EVENT_CLICKED);
 tolua_constant(tolua_S,"MAW_EVENT_ITEM_CLICKED",MAW_EVENT_ITEM_CLICKED);
 tolua_constant(tolua_S,"MAW_EVENT_TAB_CHANGED",MAW_EVENT_TAB_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_GL_VIEW_READY",MAW_EVENT_GL_VIEW_READY);
 tolua_constant(tolua_S,"MAW_EVENT_WEB_VIEW_URL_CHANGED",MAW_EVENT_WEB_VIEW_URL_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_STACK_SCREEN_POPPED",MAW_EVENT_STACK_SCREEN_POPPED);
 tolua_constant(tolua_S,"MAW_EVENT_SLIDER_VALUE_CHANGED",MAW_EVENT_SLIDER_VALUE_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_DATE_PICKER_VALUE_CHANGED",MAW_EVENT_DATE_PICKER_VALUE_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_TIME_PICKER_VALUE_CHANGED",MAW_EVENT_TIME_PICKER_VALUE_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_NUMBER_PICKER_VALUE_CHANGED",MAW_EVENT_NUMBER_PICKER_VALUE_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_VIDEO_STATE_CHANGED",MAW_EVENT_VIDEO_STATE_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_EDIT_BOX_EDITING_DID_BEGIN",MAW_EVENT_EDIT_BOX_EDITING_DID_BEGIN);
 tolua_constant(tolua_S,"MAW_EVENT_EDIT_BOX_EDITING_DID_END",MAW_EVENT_EDIT_BOX_EDITING_DID_END);
 tolua_constant(tolua_S,"MAW_EVENT_EDIT_BOX_TEXT_CHANGED",MAW_EVENT_EDIT_BOX_TEXT_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_EDIT_BOX_RETURN",MAW_EVENT_EDIT_BOX_RETURN);
 tolua_constant(tolua_S,"MAW_EVENT_WEB_VIEW_CONTENT_LOADING",MAW_EVENT_WEB_VIEW_CONTENT_LOADING);
 tolua_constant(tolua_S,"MAW_EVENT_WEB_VIEW_HOOK_INVOKED",MAW_EVENT_WEB_VIEW_HOOK_INVOKED);
 tolua_constant(tolua_S,"MAW_EVENT_DIALOG_DISMISSED",MAW_EVENT_DIALOG_DISMISSED);
 tolua_constant(tolua_S,"MAW_EVENT_SCREEN_ORIENTATION_WILL_CHANGE",MAW_EVENT_SCREEN_ORIENTATION_WILL_CHANGE);
 tolua_constant(tolua_S,"MAW_EVENT_SCREEN_ORIENTATION_DID_CHANGE",MAW_EVENT_SCREEN_ORIENTATION_DID_CHANGE);
 tolua_constant(tolua_S,"MAW_EVENT_RATING_BAR_VALUE_CHANGED",MAW_EVENT_RATING_BAR_VALUE_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_RADIO_GROUP_ITEM_SELECTED",MAW_EVENT_RADIO_GROUP_ITEM_SELECTED);
 tolua_constant(tolua_S,"MAW_EVENT_RADIO_BUTTON_STATE_CHANGED",MAW_EVENT_RADIO_BUTTON_STATE_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_OPTIONS_MENU_CLOSED",MAW_EVENT_OPTIONS_MENU_CLOSED);
 tolua_constant(tolua_S,"MAW_EVENT_OPTIONS_MENU_ITEM_SELECTED",MAW_EVENT_OPTIONS_MENU_ITEM_SELECTED);
 tolua_constant(tolua_S,"MAW_EVENT_MAP_ZOOM_LEVEL_CHANGED",MAW_EVENT_MAP_ZOOM_LEVEL_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_MAP_REGION_CHANGED",MAW_EVENT_MAP_REGION_CHANGED);
 tolua_constant(tolua_S,"MAW_EVENT_MAP_PIN_CLICKED",MAW_EVENT_MAP_PIN_CLICKED);
 tolua_constant(tolua_S,"MAW_CONSTANT_MOSYNC_SCREEN_HANDLE",MAW_CONSTANT_MOSYNC_SCREEN_HANDLE);
 tolua_constant(tolua_S,"MAW_CONSTANT_FILL_AVAILABLE_SPACE",MAW_CONSTANT_FILL_AVAILABLE_SPACE);
 tolua_constant(tolua_S,"MAW_CONSTANT_WRAP_CONTENT",MAW_CONSTANT_WRAP_CONTENT);
 tolua_constant(tolua_S,"MAW_CONSTANT_STARTED",MAW_CONSTANT_STARTED);
 tolua_constant(tolua_S,"MAW_CONSTANT_DONE",MAW_CONSTANT_DONE);
 tolua_constant(tolua_S,"MAW_CONSTANT_STOPPED",MAW_CONSTANT_STOPPED);
 tolua_constant(tolua_S,"MAW_CONSTANT_ERROR",MAW_CONSTANT_ERROR);
 tolua_constant(tolua_S,"MAW_CONSTANT_SOFT",MAW_CONSTANT_SOFT);
 tolua_constant(tolua_S,"MAW_CONSTANT_HARD",MAW_CONSTANT_HARD);
 tolua_constant(tolua_S,"MAW_CONSTANT_MESSAGE",MAW_CONSTANT_MESSAGE);
 tolua_constant(tolua_S,"MAW_CONSTANT_ARROW_UP",MAW_CONSTANT_ARROW_UP);
 tolua_constant(tolua_S,"MAW_CONSTANT_ARROW_DOWN",MAW_CONSTANT_ARROW_DOWN);
 tolua_constant(tolua_S,"MAW_CONSTANT_ARROW_LEFT",MAW_CONSTANT_ARROW_LEFT);
 tolua_constant(tolua_S,"MAW_CONSTANT_ARROW_RIGHT",MAW_CONSTANT_ARROW_RIGHT);
 tolua_constant(tolua_S,"MAW_CONSTANT_ARROW_ANY",MAW_CONSTANT_ARROW_ANY);
 tolua_constant_string(tolua_S,"MAW_ALIGNMENT_LEFT",MAW_ALIGNMENT_LEFT);
 tolua_constant_string(tolua_S,"MAW_ALIGNMENT_RIGHT",MAW_ALIGNMENT_RIGHT);
 tolua_constant_string(tolua_S,"MAW_ALIGNMENT_CENTER",MAW_ALIGNMENT_CENTER);
 tolua_constant_string(tolua_S,"MAW_ALIGNMENT_TOP",MAW_ALIGNMENT_TOP);
 tolua_constant_string(tolua_S,"MAW_ALIGNMENT_BOTTOM",MAW_ALIGNMENT_BOTTOM);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_ACTION_PLAY",MAW_VIDEO_VIEW_ACTION_PLAY);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_ACTION_PAUSE",MAW_VIDEO_VIEW_ACTION_PAUSE);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_ACTION_STOP",MAW_VIDEO_VIEW_ACTION_STOP);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_STATE_PLAYING",MAW_VIDEO_VIEW_STATE_PLAYING);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_STATE_PAUSED",MAW_VIDEO_VIEW_STATE_PAUSED);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_STATE_STOPPED",MAW_VIDEO_VIEW_STATE_STOPPED);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_STATE_FINISHED",MAW_VIDEO_VIEW_STATE_FINISHED);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_STATE_SOURCE_READY",MAW_VIDEO_VIEW_STATE_SOURCE_READY);
 tolua_constant(tolua_S,"MAW_VIDEO_VIEW_STATE_INTERRUPTED",MAW_VIDEO_VIEW_STATE_INTERRUPTED);
 tolua_constant(tolua_S,"MAW_RES_OK",MAW_RES_OK);
 tolua_constant(tolua_S,"MAW_RES_ERROR",MAW_RES_ERROR);
 tolua_constant(tolua_S,"MAW_RES_INVALID_PROPERTY_NAME",MAW_RES_INVALID_PROPERTY_NAME);
 tolua_constant(tolua_S,"MAW_RES_INVALID_PROPERTY_VALUE",MAW_RES_INVALID_PROPERTY_VALUE);
 tolua_constant(tolua_S,"MAW_RES_INVALID_HANDLE",MAW_RES_INVALID_HANDLE);
 tolua_constant(tolua_S,"MAW_RES_INVALID_TYPE_NAME",MAW_RES_INVALID_TYPE_NAME);
 tolua_constant(tolua_S,"MAW_RES_INVALID_INDEX",MAW_RES_INVALID_INDEX);
 tolua_constant(tolua_S,"MAW_RES_INVALID_STRING_BUFFER_SIZE",MAW_RES_INVALID_STRING_BUFFER_SIZE);
 tolua_constant(tolua_S,"MAW_RES_INVALID_SCREEN",MAW_RES_INVALID_SCREEN);
 tolua_constant(tolua_S,"MAW_RES_INVALID_LAYOUT",MAW_RES_INVALID_LAYOUT);
 tolua_constant(tolua_S,"MAW_RES_REMOVED_ROOT",MAW_RES_REMOVED_ROOT);
 tolua_constant(tolua_S,"MAW_RES_FEATURE_NOT_AVAILABLE",MAW_RES_FEATURE_NOT_AVAILABLE);
 tolua_constant(tolua_S,"MAW_RES_CANNOT_INSERT_DIALOG",MAW_RES_CANNOT_INSERT_DIALOG);
 tolua_constant_string(tolua_S,"MAW_SCREEN",MAW_SCREEN);
 tolua_constant_string(tolua_S,"MAW_TAB_SCREEN",MAW_TAB_SCREEN);
 tolua_constant_string(tolua_S,"MAW_STACK_SCREEN",MAW_STACK_SCREEN);
 tolua_constant_string(tolua_S,"MAW_BUTTON",MAW_BUTTON);
 tolua_constant_string(tolua_S,"MAW_IMAGE",MAW_IMAGE);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON",MAW_IMAGE_BUTTON);
 tolua_constant_string(tolua_S,"MAW_LABEL",MAW_LABEL);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX",MAW_EDIT_BOX);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW",MAW_LIST_VIEW);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW_ITEM",MAW_LIST_VIEW_ITEM);
 tolua_constant_string(tolua_S,"MAW_CHECK_BOX",MAW_CHECK_BOX);
 tolua_constant_string(tolua_S,"MAW_HORIZONTAL_LAYOUT",MAW_HORIZONTAL_LAYOUT);
 tolua_constant_string(tolua_S,"MAW_VERTICAL_LAYOUT",MAW_VERTICAL_LAYOUT);
 tolua_constant_string(tolua_S,"MAW_RELATIVE_LAYOUT",MAW_RELATIVE_LAYOUT);
 tolua_constant_string(tolua_S,"MAW_SEARCH_BAR",MAW_SEARCH_BAR);
 tolua_constant_string(tolua_S,"MAW_NAV_BAR",MAW_NAV_BAR);
 tolua_constant_string(tolua_S,"MAW_GL_VIEW",MAW_GL_VIEW);
 tolua_constant_string(tolua_S,"MAW_GL2_VIEW",MAW_GL2_VIEW);
 tolua_constant_string(tolua_S,"MAW_CAMERA_PREVIEW",MAW_CAMERA_PREVIEW);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW",MAW_WEB_VIEW);
 tolua_constant_string(tolua_S,"MAW_PROGRESS_BAR",MAW_PROGRESS_BAR);
 tolua_constant_string(tolua_S,"MAW_ACTIVITY_INDICATOR",MAW_ACTIVITY_INDICATOR);
 tolua_constant_string(tolua_S,"MAW_SLIDER",MAW_SLIDER);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER",MAW_DATE_PICKER);
 tolua_constant_string(tolua_S,"MAW_TIME_PICKER",MAW_TIME_PICKER);
 tolua_constant_string(tolua_S,"MAW_NUMBER_PICKER",MAW_NUMBER_PICKER);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW",MAW_VIDEO_VIEW);
 tolua_constant_string(tolua_S,"MAW_TOGGLE_BUTTON",MAW_TOGGLE_BUTTON);
 tolua_constant_string(tolua_S,"MAW_MODAL_DIALOG",MAW_MODAL_DIALOG);
 tolua_constant_string(tolua_S,"MAW_PANORAMA_VIEW",MAW_PANORAMA_VIEW);
 tolua_constant_string(tolua_S,"MAW_RADIO_BUTTON",MAW_RADIO_BUTTON);
 tolua_constant_string(tolua_S,"MAW_RADIO_GROUP",MAW_RADIO_GROUP);
 tolua_constant_string(tolua_S,"MAW_RATING_BAR",MAW_RATING_BAR);
 tolua_constant_string(tolua_S,"MAW_MAP",MAW_MAP);
 tolua_constant_string(tolua_S,"MAW_MAP_PIN",MAW_MAP_PIN);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_ADD",MAW_OPTIONS_MENU_ICON_CONSTANT_ADD);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_AGENDA",MAW_OPTIONS_MENU_ICON_CONSTANT_AGENDA);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_ALWAYS_LANDSCAPE_PORTRAIT",MAW_OPTIONS_MENU_ICON_CONSTANT_ALWAYS_LANDSCAPE_PORTRAIT);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_CALL",MAW_OPTIONS_MENU_ICON_CONSTANT_CALL);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_CAMERA",MAW_OPTIONS_MENU_ICON_CONSTANT_CAMERA);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_CLOSE_CLEAR_CANCEL",MAW_OPTIONS_MENU_ICON_CONSTANT_CLOSE_CLEAR_CANCEL);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_COMPASS",MAW_OPTIONS_MENU_ICON_CONSTANT_COMPASS);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_CROP",MAW_OPTIONS_MENU_ICON_CONSTANT_CROP);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_DAY",MAW_OPTIONS_MENU_ICON_CONSTANT_DAY);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_DELETE",MAW_OPTIONS_MENU_ICON_CONSTANT_DELETE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_DIRECTIONS",MAW_OPTIONS_MENU_ICON_CONSTANT_DIRECTIONS);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_EDIT",MAW_OPTIONS_MENU_ICON_CONSTANT_EDIT);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_GALLERY",MAW_OPTIONS_MENU_ICON_CONSTANT_GALLERY);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_HELP",MAW_OPTIONS_MENU_ICON_CONSTANT_HELP);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_INFO_DETAILS",MAW_OPTIONS_MENU_ICON_CONSTANT_INFO_DETAILS);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_MANAGE",MAW_OPTIONS_MENU_ICON_CONSTANT_MANAGE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_MAPMODE",MAW_OPTIONS_MENU_ICON_CONSTANT_MAPMODE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_MONTH",MAW_OPTIONS_MENU_ICON_CONSTANT_MONTH);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_MORE",MAW_OPTIONS_MENU_ICON_CONSTANT_MORE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_MY_CALENDAR",MAW_OPTIONS_MENU_ICON_CONSTANT_MY_CALENDAR);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_MYLOCATION",MAW_OPTIONS_MENU_ICON_CONSTANT_MYLOCATION);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_MYPLACES",MAW_OPTIONS_MENU_ICON_CONSTANT_MYPLACES);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_PREFERENCES",MAW_OPTIONS_MENU_ICON_CONSTANT_PREFERENCES);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_RECENT_HISTORY",MAW_OPTIONS_MENU_ICON_CONSTANT_RECENT_HISTORY);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_REPORT_IMAGE",MAW_OPTIONS_MENU_ICON_CONSTANT_REPORT_IMAGE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_REVERT",MAW_OPTIONS_MENU_ICON_CONSTANT_REVERT);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_ROTATE",MAW_OPTIONS_MENU_ICON_CONSTANT_ROTATE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_SAVE",MAW_OPTIONS_MENU_ICON_CONSTANT_SAVE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_SEARCH",MAW_OPTIONS_MENU_ICON_CONSTANT_SEARCH);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_SEND",MAW_OPTIONS_MENU_ICON_CONSTANT_SEND);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_SET_AS",MAW_OPTIONS_MENU_ICON_CONSTANT_SET_AS);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_SHARE",MAW_OPTIONS_MENU_ICON_CONSTANT_SHARE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_SLIDESHOW",MAW_OPTIONS_MENU_ICON_CONSTANT_SLIDESHOW);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_SORT_ALPHABETICALLY",MAW_OPTIONS_MENU_ICON_CONSTANT_SORT_ALPHABETICALLY);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_SORT_BY_SIZE",MAW_OPTIONS_MENU_ICON_CONSTANT_SORT_BY_SIZE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_TODAY",MAW_OPTIONS_MENU_ICON_CONSTANT_TODAY);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_UPLOAD",MAW_OPTIONS_MENU_ICON_CONSTANT_UPLOAD);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_UPLOAD_YOU_TUBE",MAW_OPTIONS_MENU_ICON_CONSTANT_UPLOAD_YOU_TUBE);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_VIEW",MAW_OPTIONS_MENU_ICON_CONSTANT_VIEW);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_WEEK",MAW_OPTIONS_MENU_ICON_CONSTANT_WEEK);
 tolua_constant_string(tolua_S,"MAW_OPTIONS_MENU_ICON_CONSTANT_ZOOM",MAW_OPTIONS_MENU_ICON_CONSTANT_ZOOM);
 tolua_constant_string(tolua_S,"MAW_WIDGET_LEFT",MAW_WIDGET_LEFT);
 tolua_constant_string(tolua_S,"MAW_WIDGET_TOP",MAW_WIDGET_TOP);
 tolua_constant_string(tolua_S,"MAW_WIDGET_WIDTH",MAW_WIDGET_WIDTH);
 tolua_constant_string(tolua_S,"MAW_WIDGET_HEIGHT",MAW_WIDGET_HEIGHT);
 tolua_constant_string(tolua_S,"MAW_WIDGET_ALPHA",MAW_WIDGET_ALPHA);
 tolua_constant_string(tolua_S,"MAW_WIDGET_BACKGROUND_COLOR",MAW_WIDGET_BACKGROUND_COLOR);
 tolua_constant_string(tolua_S,"MAW_WIDGET_VISIBLE",MAW_WIDGET_VISIBLE);
 tolua_constant_string(tolua_S,"MAW_WIDGET_ENABLED",MAW_WIDGET_ENABLED);
 tolua_constant_string(tolua_S,"MAW_WIDGET_BACKGROUND_GRADIENT",MAW_WIDGET_BACKGROUND_GRADIENT);
 tolua_constant_string(tolua_S,"MAW_SCREEN_TITLE",MAW_SCREEN_TITLE);
 tolua_constant_string(tolua_S,"MAW_SCREEN_ICON",MAW_SCREEN_ICON);
 tolua_constant_string(tolua_S,"MAW_SCREEN_REMOVE_OPTIONS_MENU",MAW_SCREEN_REMOVE_OPTIONS_MENU);
 tolua_constant_string(tolua_S,"MAW_TAB_SCREEN_TITLE",MAW_TAB_SCREEN_TITLE);
 tolua_constant_string(tolua_S,"MAW_TAB_SCREEN_ICON",MAW_TAB_SCREEN_ICON);
 tolua_constant_string(tolua_S,"MAW_TAB_SCREEN_CURRENT_TAB",MAW_TAB_SCREEN_CURRENT_TAB);
 tolua_constant_string(tolua_S,"MAW_PANORAMA_VIEW_TITLE",MAW_PANORAMA_VIEW_TITLE);
 tolua_constant_string(tolua_S,"MAW_PANORAMA_VIEW_CURRENT_SCREEN",MAW_PANORAMA_VIEW_CURRENT_SCREEN);
 tolua_constant_string(tolua_S,"MAW_PANORAMA_VIEW_BACKGROUND_IMAGE",MAW_PANORAMA_VIEW_BACKGROUND_IMAGE);
 tolua_constant_string(tolua_S,"MAW_STACK_SCREEN_TITLE",MAW_STACK_SCREEN_TITLE);
 tolua_constant_string(tolua_S,"MAW_STACK_SCREEN_ICON",MAW_STACK_SCREEN_ICON);
 tolua_constant_string(tolua_S,"MAW_STACK_SCREEN_BACK_BUTTON_ENABLED",MAW_STACK_SCREEN_BACK_BUTTON_ENABLED);
 tolua_constant_string(tolua_S,"MAW_LABEL_TEXT",MAW_LABEL_TEXT);
 tolua_constant_string(tolua_S,"MAW_LABEL_TEXT_VERTICAL_ALIGNMENT",MAW_LABEL_TEXT_VERTICAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_LABEL_TEXT_HORIZONTAL_ALIGNMENT",MAW_LABEL_TEXT_HORIZONTAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_LABEL_FONT_COLOR",MAW_LABEL_FONT_COLOR);
 tolua_constant_string(tolua_S,"MAW_LABEL_FONT_SIZE",MAW_LABEL_FONT_SIZE);
 tolua_constant_string(tolua_S,"MAW_LABEL_FONT_HANDLE",MAW_LABEL_FONT_HANDLE);
 tolua_constant_string(tolua_S,"MAW_LABEL_MAX_NUMBER_OF_LINES",MAW_LABEL_MAX_NUMBER_OF_LINES);
 tolua_constant_string(tolua_S,"MAW_BUTTON_TEXT",MAW_BUTTON_TEXT);
 tolua_constant_string(tolua_S,"MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT",MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT",MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_BUTTON_FONT_COLOR",MAW_BUTTON_FONT_COLOR);
 tolua_constant_string(tolua_S,"MAW_BUTTON_FONT_SIZE",MAW_BUTTON_FONT_SIZE);
 tolua_constant_string(tolua_S,"MAW_BUTTON_FONT_HANDLE",MAW_BUTTON_FONT_HANDLE);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON_TEXT",MAW_IMAGE_BUTTON_TEXT);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON_TEXT_VERTICAL_ALIGNMENT",MAW_IMAGE_BUTTON_TEXT_VERTICAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON_TEXT_HORIZONTAL_ALIGNMENT",MAW_IMAGE_BUTTON_TEXT_HORIZONTAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON_FONT_COLOR",MAW_IMAGE_BUTTON_FONT_COLOR);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON_FONT_SIZE",MAW_IMAGE_BUTTON_FONT_SIZE);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON_BACKGROUND_IMAGE",MAW_IMAGE_BUTTON_BACKGROUND_IMAGE);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON_IMAGE",MAW_IMAGE_BUTTON_IMAGE);
 tolua_constant_string(tolua_S,"MAW_IMAGE_BUTTON_FONT_HANDLE",MAW_IMAGE_BUTTON_FONT_HANDLE);
 tolua_constant_string(tolua_S,"MAW_IMAGE_IMAGE",MAW_IMAGE_IMAGE);
 tolua_constant_string(tolua_S,"MAW_IMAGE_SCALE_MODE",MAW_IMAGE_SCALE_MODE);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_TYPE_ANY",MAW_EDIT_BOX_TYPE_ANY);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_TYPE_EMAILADDR",MAW_EDIT_BOX_TYPE_EMAILADDR);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_TYPE_NUMERIC",MAW_EDIT_BOX_TYPE_NUMERIC);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_TYPE_PHONENUMBER",MAW_EDIT_BOX_TYPE_PHONENUMBER);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_TYPE_URL",MAW_EDIT_BOX_TYPE_URL);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_TYPE_DECIMAL",MAW_EDIT_BOX_TYPE_DECIMAL);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_TYPE_SINGLE_LINE",MAW_EDIT_BOX_TYPE_SINGLE_LINE);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_FLAG_PASSWORD",MAW_EDIT_BOX_FLAG_PASSWORD);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_FLAG_SENSITIVE",MAW_EDIT_BOX_FLAG_SENSITIVE);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_FLAG_INITIAL_CAPS_WORD",MAW_EDIT_BOX_FLAG_INITIAL_CAPS_WORD);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_FLAG_INITIAL_CAPS_SENTENCE",MAW_EDIT_BOX_FLAG_INITIAL_CAPS_SENTENCE);
 tolua_constant(tolua_S,"MAW_EDIT_BOX_FLAG_INITIAL_CAPS_ALL_CHARACTERS",MAW_EDIT_BOX_FLAG_INITIAL_CAPS_ALL_CHARACTERS);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_TEXT",MAW_EDIT_BOX_TEXT);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_PLACEHOLDER",MAW_EDIT_BOX_PLACEHOLDER);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_SHOW_KEYBOARD",MAW_EDIT_BOX_SHOW_KEYBOARD);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_EDIT_MODE",MAW_EDIT_BOX_EDIT_MODE);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_INPUT_MODE",MAW_EDIT_BOX_INPUT_MODE);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_INPUT_FLAG",MAW_EDIT_BOX_INPUT_FLAG);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_FONT_COLOR",MAW_EDIT_BOX_FONT_COLOR);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_LINES_NUMBER",MAW_EDIT_BOX_LINES_NUMBER);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_MAX_LINES",MAW_EDIT_BOX_MAX_LINES);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_MIN_LINES",MAW_EDIT_BOX_MIN_LINES);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_MAX_LENGTH",MAW_EDIT_BOX_MAX_LENGTH);
 tolua_constant_string(tolua_S,"MAW_EDIT_BOX_PLACEHOLDER_FONT_COLOR",MAW_EDIT_BOX_PLACEHOLDER_FONT_COLOR);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW_ITEM_TEXT",MAW_LIST_VIEW_ITEM_TEXT);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW_ITEM_ICON",MAW_LIST_VIEW_ITEM_ICON);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE",MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW_ITEM_FONT_COLOR",MAW_LIST_VIEW_ITEM_FONT_COLOR);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW_ITEM_FONT_SIZE",MAW_LIST_VIEW_ITEM_FONT_SIZE);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW_ITEM_FONT_HANDLE",MAW_LIST_VIEW_ITEM_FONT_HANDLE);
 tolua_constant_string(tolua_S,"MAW_LIST_VIEW_REQUEST_FOCUS",MAW_LIST_VIEW_REQUEST_FOCUS);
 tolua_constant_string(tolua_S,"MAW_CHECK_BOX_CHECKED",MAW_CHECK_BOX_CHECKED);
 tolua_constant_string(tolua_S,"MAW_TOGGLE_BUTTON_CHECKED",MAW_TOGGLE_BUTTON_CHECKED);
 tolua_constant_string(tolua_S,"MAW_HORIZONTAL_LAYOUT_CHILD_VERTICAL_ALIGNMENT",MAW_HORIZONTAL_LAYOUT_CHILD_VERTICAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_HORIZONTAL_LAYOUT_CHILD_HORIZONTAL_ALIGNMENT",MAW_HORIZONTAL_LAYOUT_CHILD_HORIZONTAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_HORIZONTAL_LAYOUT_PADDING_TOP",MAW_HORIZONTAL_LAYOUT_PADDING_TOP);
 tolua_constant_string(tolua_S,"MAW_HORIZONTAL_LAYOUT_PADDING_LEFT",MAW_HORIZONTAL_LAYOUT_PADDING_LEFT);
 tolua_constant_string(tolua_S,"MAW_HORIZONTAL_LAYOUT_PADDING_RIGHT",MAW_HORIZONTAL_LAYOUT_PADDING_RIGHT);
 tolua_constant_string(tolua_S,"MAW_HORIZONTAL_LAYOUT_PADDING_BOTTOM",MAW_HORIZONTAL_LAYOUT_PADDING_BOTTOM);
 tolua_constant_string(tolua_S,"MAW_RELATIVE_LAYOUT_SCROLLABLE",MAW_RELATIVE_LAYOUT_SCROLLABLE);
 tolua_constant_string(tolua_S,"MAW_RELATIVE_LAYOUT_CONTENT_OFFSET",MAW_RELATIVE_LAYOUT_CONTENT_OFFSET);
 tolua_constant_string(tolua_S,"MAW_VERTICAL_LAYOUT_CHILD_VERTICAL_ALIGNMENT",MAW_VERTICAL_LAYOUT_CHILD_VERTICAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_VERTICAL_LAYOUT_CHILD_HORIZONTAL_ALIGNMENT",MAW_VERTICAL_LAYOUT_CHILD_HORIZONTAL_ALIGNMENT);
 tolua_constant_string(tolua_S,"MAW_VERTICAL_LAYOUT_PADDING_TOP",MAW_VERTICAL_LAYOUT_PADDING_TOP);
 tolua_constant_string(tolua_S,"MAW_VERTICAL_LAYOUT_PADDING_LEFT",MAW_VERTICAL_LAYOUT_PADDING_LEFT);
 tolua_constant_string(tolua_S,"MAW_VERTICAL_LAYOUT_PADDING_RIGHT",MAW_VERTICAL_LAYOUT_PADDING_RIGHT);
 tolua_constant_string(tolua_S,"MAW_VERTICAL_LAYOUT_PADDING_BOTTOM",MAW_VERTICAL_LAYOUT_PADDING_BOTTOM);
 tolua_constant_string(tolua_S,"MAW_VERTICAL_LAYOUT_SCROLLABLE",MAW_VERTICAL_LAYOUT_SCROLLABLE);
 tolua_constant_string(tolua_S,"MAW_SEARCH_BAR_TEXT",MAW_SEARCH_BAR_TEXT);
 tolua_constant_string(tolua_S,"MAW_SEARCH_BAR_PLACEHOLDER",MAW_SEARCH_BAR_PLACEHOLDER);
 tolua_constant_string(tolua_S,"MAW_SEARCH_BAR_SHOW_KEYBOARD",MAW_SEARCH_BAR_SHOW_KEYBOARD);
 tolua_constant_string(tolua_S,"MAW_GL_VIEW_INVALIDATE",MAW_GL_VIEW_INVALIDATE);
 tolua_constant_string(tolua_S,"MAW_GL_VIEW_BIND",MAW_GL_VIEW_BIND);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_URL",MAW_WEB_VIEW_URL);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_HTML",MAW_WEB_VIEW_HTML);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_BASE_URL",MAW_WEB_VIEW_BASE_URL);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_SOFT_HOOK",MAW_WEB_VIEW_SOFT_HOOK);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_HARD_HOOK",MAW_WEB_VIEW_HARD_HOOK);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_NEW_URL",MAW_WEB_VIEW_NEW_URL);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_HORIZONTAL_SCROLL_BAR_ENABLED",MAW_WEB_VIEW_HORIZONTAL_SCROLL_BAR_ENABLED);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_VERTICAL_SCROLL_BAR_ENABLED",MAW_WEB_VIEW_VERTICAL_SCROLL_BAR_ENABLED);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_ENABLE_ZOOM",MAW_WEB_VIEW_ENABLE_ZOOM);
 tolua_constant_string(tolua_S,"MAW_WEB_VIEW_NAVIGATE",MAW_WEB_VIEW_NAVIGATE);
 tolua_constant_string(tolua_S,"MAW_PROGRESS_BAR_MAX",MAW_PROGRESS_BAR_MAX);
 tolua_constant_string(tolua_S,"MAW_PROGRESS_BAR_PROGRESS",MAW_PROGRESS_BAR_PROGRESS);
 tolua_constant_string(tolua_S,"MAW_PROGRESS_BAR_INCREMENT_PROGRESS",MAW_PROGRESS_BAR_INCREMENT_PROGRESS);
 tolua_constant_string(tolua_S,"MAW_ACTIVITY_INDICATOR_IN_PROGRESS",MAW_ACTIVITY_INDICATOR_IN_PROGRESS);
 tolua_constant_string(tolua_S,"MAW_SLIDER_MAX",MAW_SLIDER_MAX);
 tolua_constant_string(tolua_S,"MAW_SLIDER_VALUE",MAW_SLIDER_VALUE);
 tolua_constant_string(tolua_S,"MAW_SLIDER_INCREASE_VALUE",MAW_SLIDER_INCREASE_VALUE);
 tolua_constant_string(tolua_S,"MAW_SLIDER_DECREASE_VALUE",MAW_SLIDER_DECREASE_VALUE);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MAX_DATE",MAW_DATE_PICKER_MAX_DATE);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MAX_DATE_YEAR",MAW_DATE_PICKER_MAX_DATE_YEAR);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MAX_DATE_MONTH",MAW_DATE_PICKER_MAX_DATE_MONTH);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MAX_DATE_DAY",MAW_DATE_PICKER_MAX_DATE_DAY);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MIN_DATE",MAW_DATE_PICKER_MIN_DATE);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MIN_DATE_YEAR",MAW_DATE_PICKER_MIN_DATE_YEAR);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MIN_DATE_MONTH",MAW_DATE_PICKER_MIN_DATE_MONTH);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MIN_DATE_DAY",MAW_DATE_PICKER_MIN_DATE_DAY);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_YEAR",MAW_DATE_PICKER_YEAR);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_MONTH",MAW_DATE_PICKER_MONTH);
 tolua_constant_string(tolua_S,"MAW_DATE_PICKER_DAY_OF_MONTH",MAW_DATE_PICKER_DAY_OF_MONTH);
 tolua_constant_string(tolua_S,"MAW_TIME_PICKER_CURRENT_HOUR",MAW_TIME_PICKER_CURRENT_HOUR);
 tolua_constant_string(tolua_S,"MAW_TIME_PICKER_CURRENT_MINUTE",MAW_TIME_PICKER_CURRENT_MINUTE);
 tolua_constant_string(tolua_S,"MAW_NUMBER_PICKER_VALUE",MAW_NUMBER_PICKER_VALUE);
 tolua_constant_string(tolua_S,"MAW_NUMBER_PICKER_MIN_VALUE",MAW_NUMBER_PICKER_MIN_VALUE);
 tolua_constant_string(tolua_S,"MAW_NUMBER_PICKER_MAX_VALUE",MAW_NUMBER_PICKER_MAX_VALUE);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW_PATH",MAW_VIDEO_VIEW_PATH);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW_URL",MAW_VIDEO_VIEW_URL);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW_ACTION",MAW_VIDEO_VIEW_ACTION);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW_SEEK_TO",MAW_VIDEO_VIEW_SEEK_TO);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW_DURATION",MAW_VIDEO_VIEW_DURATION);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW_BUFFER_PERCENTAGE",MAW_VIDEO_VIEW_BUFFER_PERCENTAGE);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW_CURRENT_POSITION",MAW_VIDEO_VIEW_CURRENT_POSITION);
 tolua_constant_string(tolua_S,"MAW_VIDEO_VIEW_CONTROL",MAW_VIDEO_VIEW_CONTROL);
 tolua_constant_string(tolua_S,"MAW_NAV_BAR_TITLE",MAW_NAV_BAR_TITLE);
 tolua_constant_string(tolua_S,"MAW_NAV_BAR_ICON",MAW_NAV_BAR_ICON);
 tolua_constant_string(tolua_S,"MAW_NAV_BAR_BACK_BTN",MAW_NAV_BAR_BACK_BTN);
 tolua_constant_string(tolua_S,"MAW_NAV_BAR_TITLE_FONT_COLOR",MAW_NAV_BAR_TITLE_FONT_COLOR);
 tolua_constant_string(tolua_S,"MAW_NAV_BAR_TITLE_FONT_SIZE",MAW_NAV_BAR_TITLE_FONT_SIZE);
 tolua_constant_string(tolua_S,"MAW_NAV_BAR_TITLE_FONT_HANDLE",MAW_NAV_BAR_TITLE_FONT_HANDLE);
 tolua_constant_string(tolua_S,"MAW_MODAL_DIALOG_TITLE",MAW_MODAL_DIALOG_TITLE);
 tolua_constant_string(tolua_S,"MAW_MODAL_DIALOG_ARROW_POSITION",MAW_MODAL_DIALOG_ARROW_POSITION);
 tolua_constant_string(tolua_S,"MAW_MODAL_DIALOG_USER_CAN_DISMISS",MAW_MODAL_DIALOG_USER_CAN_DISMISS);
 tolua_constant_string(tolua_S,"MAW_RADIO_BUTTON_CHECKED",MAW_RADIO_BUTTON_CHECKED);
 tolua_constant_string(tolua_S,"MAW_RADIO_BUTTON_TOGGLE",MAW_RADIO_BUTTON_TOGGLE);
 tolua_constant_string(tolua_S,"MAW_RADIO_BUTTON_TEXT",MAW_RADIO_BUTTON_TEXT);
 tolua_constant_string(tolua_S,"MAW_RADIO_BUTTON_TEXT_COLOR",MAW_RADIO_BUTTON_TEXT_COLOR);
 tolua_constant_string(tolua_S,"MAW_RADIO_GROUP_ADD_VIEW",MAW_RADIO_GROUP_ADD_VIEW);
 tolua_constant_string(tolua_S,"MAW_RADIO_GROUP_CLEAR_CHECK",MAW_RADIO_GROUP_CLEAR_CHECK);
 tolua_constant_string(tolua_S,"MAW_RADIO_GROUP_SELECTED",MAW_RADIO_GROUP_SELECTED);
 tolua_constant_string(tolua_S,"MAW_RATING_BAR_NUM_STAR",MAW_RATING_BAR_NUM_STAR);
 tolua_constant_string(tolua_S,"MAW_RATING_BAR_RATING",MAW_RATING_BAR_RATING);
 tolua_constant_string(tolua_S,"MAW_RATING_BAR_GRANULARITY",MAW_RATING_BAR_GRANULARITY);
 tolua_constant(tolua_S,"MAW_MAP_TYPE_ROAD",MAW_MAP_TYPE_ROAD);
 tolua_constant(tolua_S,"MAW_MAP_TYPE_SATELLITE",MAW_MAP_TYPE_SATELLITE);
 tolua_constant_string(tolua_S,"MAW_MAP_API_KEY_GOOGLE",MAW_MAP_API_KEY_GOOGLE);
 tolua_constant_string(tolua_S,"MAW_MAP_API_KEY_BING",MAW_MAP_API_KEY_BING);
 tolua_constant_string(tolua_S,"MAW_MAP_TYPE",MAW_MAP_TYPE);
 tolua_constant_string(tolua_S,"MAW_MAP_ZOOM_LEVEL",MAW_MAP_ZOOM_LEVEL);
 tolua_constant_string(tolua_S,"MAW_MAP_INTERRACTION_ENABLED",MAW_MAP_INTERRACTION_ENABLED);
 tolua_constant_string(tolua_S,"MAW_MAP_CENTER_LATITUDE",MAW_MAP_CENTER_LATITUDE);
 tolua_constant_string(tolua_S,"MAW_MAP_CENTER_LONGITUDE",MAW_MAP_CENTER_LONGITUDE);
 tolua_constant_string(tolua_S,"MAW_MAP_CENTER_ZOOM_LEVEL",MAW_MAP_CENTER_ZOOM_LEVEL);
 tolua_constant_string(tolua_S,"MAW_MAP_CENTERED",MAW_MAP_CENTERED);
 tolua_constant_string(tolua_S,"MAW_MAP_VISIBLE_AREA_UPPER_LEFT_CORNER_LATITUDE",MAW_MAP_VISIBLE_AREA_UPPER_LEFT_CORNER_LATITUDE);
 tolua_constant_string(tolua_S,"MAW_MAP_VISIBLE_AREA_UPPER_LEFT_CORNER_LONGITUDE",MAW_MAP_VISIBLE_AREA_UPPER_LEFT_CORNER_LONGITUDE);
 tolua_constant_string(tolua_S,"MAW_MAP_VISIBLE_AREA_LOWER_RIGHT_CORNER_LATITUDE",MAW_MAP_VISIBLE_AREA_LOWER_RIGHT_CORNER_LATITUDE);
 tolua_constant_string(tolua_S,"MAW_MAP_VISIBLE_AREA_LOWER_RIGHT_CORNER_LONGITUDE",MAW_MAP_VISIBLE_AREA_LOWER_RIGHT_CORNER_LONGITUDE);
 tolua_constant_string(tolua_S,"MAW_MAP_CENTERED_ON_VISIBLE_AREA",MAW_MAP_CENTERED_ON_VISIBLE_AREA);
 tolua_constant_string(tolua_S,"MAW_MAP_PIN_LATITUDE",MAW_MAP_PIN_LATITUDE);
 tolua_constant_string(tolua_S,"MAW_MAP_PIN_LONGITUDE",MAW_MAP_PIN_LONGITUDE);
 tolua_constant_string(tolua_S,"MAW_MAP_PIN_TEXT",MAW_MAP_PIN_TEXT);
 tolua_function(tolua_S,"maWidgetCreate",tolua_lua_maapi_mosync_maWidgetCreate00);
 tolua_function(tolua_S,"maWidgetDestroy",tolua_lua_maapi_mosync_maWidgetDestroy00);
 tolua_function(tolua_S,"maWidgetAddChild",tolua_lua_maapi_mosync_maWidgetAddChild00);
 tolua_function(tolua_S,"maWidgetInsertChild",tolua_lua_maapi_mosync_maWidgetInsertChild00);
 tolua_function(tolua_S,"maWidgetRemoveChild",tolua_lua_maapi_mosync_maWidgetRemoveChild00);
 tolua_function(tolua_S,"maWidgetModalDialogShow",tolua_lua_maapi_mosync_maWidgetModalDialogShow00);
 tolua_function(tolua_S,"maWidgetModalDialogHide",tolua_lua_maapi_mosync_maWidgetModalDialogHide00);
 tolua_function(tolua_S,"maWidgetScreenShow",tolua_lua_maapi_mosync_maWidgetScreenShow00);
 tolua_function(tolua_S,"maWidgetStackScreenPush",tolua_lua_maapi_mosync_maWidgetStackScreenPush00);
 tolua_function(tolua_S,"maWidgetStackScreenPop",tolua_lua_maapi_mosync_maWidgetStackScreenPop00);
 tolua_function(tolua_S,"maWidgetSetProperty",tolua_lua_maapi_mosync_maWidgetSetProperty00);
 tolua_function(tolua_S,"maWidgetGetProperty",tolua_lua_maapi_mosync_maWidgetGetProperty00);
 tolua_function(tolua_S,"maWidgetScreenAddOptionsMenuItem",tolua_lua_maapi_mosync_maWidgetScreenAddOptionsMenuItem00);
 tolua_function(tolua_S,"EXTENT",tolua_lua_maapi_mosync_EXTENT00);
 tolua_function(tolua_S,"EXTENT_X",tolua_lua_maapi_mosync_EXTENT_X00);
 tolua_function(tolua_S,"EXTENT_Y",tolua_lua_maapi_mosync_EXTENT_Y00);
 tolua_constant(tolua_S,"SCALETYPE_NEAREST_NEIGHBOUR",SCALETYPE_NEAREST_NEIGHBOUR);
 tolua_constant(tolua_S,"SCALETYPE_BILINEAR",SCALETYPE_BILINEAR);
 tolua_function(tolua_S,"SysImageScale",tolua_lua_maapi_mosync_SysImageScale00);
 tolua_function(tolua_S,"SysImageScaleProportionally",tolua_lua_maapi_mosync_SysImageScaleProportionally00);
 tolua_function(tolua_S,"SysTextCreate",tolua_lua_maapi_mosync_SysTextCreate00);
 tolua_function(tolua_S,"SysTextDelete",tolua_lua_maapi_mosync_SysTextDelete00);
 tolua_function(tolua_S,"SysTextSetString",tolua_lua_maapi_mosync_SysTextSetString00);
 tolua_function(tolua_S,"SysTextSetLineSpacing",tolua_lua_maapi_mosync_SysTextSetLineSpacing00);
 tolua_function(tolua_S,"SysTextGetStringSize",tolua_lua_maapi_mosync_SysTextGetStringSize00);
 tolua_function(tolua_S,"SysTextDrawString",tolua_lua_maapi_mosync_SysTextDrawString00);
 tolua_function(tolua_S,"SysAlloc",tolua_lua_maapi_mosync_SysAlloc00);
 tolua_function(tolua_S,"SysFree",tolua_lua_maapi_mosync_SysFree00);
 tolua_function(tolua_S,"SysBufferGetInt",tolua_lua_maapi_mosync_SysBufferGetInt00);
 tolua_function(tolua_S,"SysBufferSetInt",tolua_lua_maapi_mosync_SysBufferSetInt00);
 tolua_function(tolua_S,"SysBufferGetByte",tolua_lua_maapi_mosync_SysBufferGetByte00);
 tolua_function(tolua_S,"SysBufferSetByte",tolua_lua_maapi_mosync_SysBufferSetByte00);
 tolua_function(tolua_S,"SysBufferGetFloat",tolua_lua_maapi_mosync_SysBufferGetFloat00);
 tolua_function(tolua_S,"SysBufferGetDouble",tolua_lua_maapi_mosync_SysBufferGetDouble00);
 tolua_function(tolua_S,"SysBufferCopyBytes",tolua_lua_maapi_mosync_SysBufferCopyBytes00);
 tolua_function(tolua_S,"SysBufferGetBytePointer",tolua_lua_maapi_mosync_SysBufferGetBytePointer00);
 tolua_function(tolua_S,"SysSizeOfInt",tolua_lua_maapi_mosync_SysSizeOfInt00);
 tolua_function(tolua_S,"SysSizeOfFloat",tolua_lua_maapi_mosync_SysSizeOfFloat00);
 tolua_function(tolua_S,"SysSizeOfDouble",tolua_lua_maapi_mosync_SysSizeOfDouble00);
 tolua_function(tolua_S,"SysBitAnd",tolua_lua_maapi_mosync_SysBitAnd00);
 tolua_function(tolua_S,"SysBitOr",tolua_lua_maapi_mosync_SysBitOr00);
 tolua_function(tolua_S,"SysBitXor",tolua_lua_maapi_mosync_SysBitXor00);
 tolua_function(tolua_S,"SysBitShiftLeft",tolua_lua_maapi_mosync_SysBitShiftLeft00);
 tolua_function(tolua_S,"SysBitShiftRight",tolua_lua_maapi_mosync_SysBitShiftRight00);
 tolua_function(tolua_S,"SysEventCreate",tolua_lua_maapi_mosync_SysEventCreate00);
 tolua_function(tolua_S,"SysEventGetType",tolua_lua_maapi_mosync_SysEventGetType00);
 tolua_function(tolua_S,"SysEventGetKey",tolua_lua_maapi_mosync_SysEventGetKey00);
 tolua_function(tolua_S,"SysEventGetNativeKey",tolua_lua_maapi_mosync_SysEventGetNativeKey00);
 tolua_function(tolua_S,"SysEventGetCharacter",tolua_lua_maapi_mosync_SysEventGetCharacter00);
 tolua_function(tolua_S,"SysEventGetX",tolua_lua_maapi_mosync_SysEventGetX00);
 tolua_function(tolua_S,"SysEventGetY",tolua_lua_maapi_mosync_SysEventGetY00);
 tolua_function(tolua_S,"SysEventGetTouchId",tolua_lua_maapi_mosync_SysEventGetTouchId00);
 tolua_function(tolua_S,"SysEventGetState",tolua_lua_maapi_mosync_SysEventGetState00);
 tolua_function(tolua_S,"SysEventGetConnHandle",tolua_lua_maapi_mosync_SysEventGetConnHandle00);
 tolua_function(tolua_S,"SysEventGetConnOpType",tolua_lua_maapi_mosync_SysEventGetConnOpType00);
 tolua_function(tolua_S,"SysEventGetConnResult",tolua_lua_maapi_mosync_SysEventGetConnResult00);
 tolua_function(tolua_S,"SysEventGetTextBoxResult",tolua_lua_maapi_mosync_SysEventGetTextBoxResult00);
 tolua_function(tolua_S,"SysEventGetTextBoxLength",tolua_lua_maapi_mosync_SysEventGetTextBoxLength00);
 tolua_function(tolua_S,"SysEventGetData",tolua_lua_maapi_mosync_SysEventGetData00);
 tolua_function(tolua_S,"SysEventSensorGetType",tolua_lua_maapi_mosync_SysEventSensorGetType00);
 tolua_function(tolua_S,"SysEventSensorGetValue1",tolua_lua_maapi_mosync_SysEventSensorGetValue100);
 tolua_function(tolua_S,"SysEventSensorGetValue2",tolua_lua_maapi_mosync_SysEventSensorGetValue200);
 tolua_function(tolua_S,"SysEventSensorGetValue3",tolua_lua_maapi_mosync_SysEventSensorGetValue300);
 tolua_function(tolua_S,"SysEventLocationGetState",tolua_lua_maapi_mosync_SysEventLocationGetState00);
 tolua_function(tolua_S,"SysEventLocationGetLat",tolua_lua_maapi_mosync_SysEventLocationGetLat00);
 tolua_function(tolua_S,"SysEventLocationGetLon",tolua_lua_maapi_mosync_SysEventLocationGetLon00);
 tolua_function(tolua_S,"SysEventLocationGetHorzAcc",tolua_lua_maapi_mosync_SysEventLocationGetHorzAcc00);
 tolua_function(tolua_S,"SysEventLocationGetVertAcc",tolua_lua_maapi_mosync_SysEventLocationGetVertAcc00);
 tolua_function(tolua_S,"SysEventLocationGetAlt",tolua_lua_maapi_mosync_SysEventLocationGetAlt00);
 tolua_function(tolua_S,"SysWidgetEventGetType",tolua_lua_maapi_mosync_SysWidgetEventGetType00);
 tolua_function(tolua_S,"SysWidgetEventGetHandle",tolua_lua_maapi_mosync_SysWidgetEventGetHandle00);
 tolua_function(tolua_S,"SysWidgetEventGetListItemIndex",tolua_lua_maapi_mosync_SysWidgetEventGetListItemIndex00);
 tolua_function(tolua_S,"SysWidgetEventGetChecked",tolua_lua_maapi_mosync_SysWidgetEventGetChecked00);
 tolua_function(tolua_S,"SysWidgetEventGetTabIndex",tolua_lua_maapi_mosync_SysWidgetEventGetTabIndex00);
 tolua_function(tolua_S,"SysWidgetEventGetUrlData",tolua_lua_maapi_mosync_SysWidgetEventGetUrlData00);
 tolua_function(tolua_S,"SysPointCreate",tolua_lua_maapi_mosync_SysPointCreate00);
 tolua_function(tolua_S,"SysPointGetX",tolua_lua_maapi_mosync_SysPointGetX00);
 tolua_function(tolua_S,"SysPointGetY",tolua_lua_maapi_mosync_SysPointGetY00);
 tolua_function(tolua_S,"SysPointSetX",tolua_lua_maapi_mosync_SysPointSetX00);
 tolua_function(tolua_S,"SysPointSetY",tolua_lua_maapi_mosync_SysPointSetY00);
 tolua_function(tolua_S,"SysRectCreate",tolua_lua_maapi_mosync_SysRectCreate00);
 tolua_function(tolua_S,"SysRectGetLeft",tolua_lua_maapi_mosync_SysRectGetLeft00);
 tolua_function(tolua_S,"SysRectGetTop",tolua_lua_maapi_mosync_SysRectGetTop00);
 tolua_function(tolua_S,"SysRectGetWidth",tolua_lua_maapi_mosync_SysRectGetWidth00);
 tolua_function(tolua_S,"SysRectGetHeight",tolua_lua_maapi_mosync_SysRectGetHeight00);
 tolua_function(tolua_S,"SysRectSetLeft",tolua_lua_maapi_mosync_SysRectSetLeft00);
 tolua_function(tolua_S,"SysRectSetTop",tolua_lua_maapi_mosync_SysRectSetTop00);
 tolua_function(tolua_S,"SysRectSetWidth",tolua_lua_maapi_mosync_SysRectSetWidth00);
 tolua_function(tolua_S,"SysRectSetHeight",tolua_lua_maapi_mosync_SysRectSetHeight00);
 tolua_function(tolua_S,"SysCopyDataCreate",tolua_lua_maapi_mosync_SysCopyDataCreate00);
 tolua_function(tolua_S,"SysScreenSetColor",tolua_lua_maapi_mosync_SysScreenSetColor00);
 tolua_function(tolua_S,"SysScreenDrawText",tolua_lua_maapi_mosync_SysScreenDrawText00);
 tolua_function(tolua_S,"SysStringCharToWideChar",tolua_lua_maapi_mosync_SysStringCharToWideChar00);
 tolua_function(tolua_S,"SysStringWideCharToChar",tolua_lua_maapi_mosync_SysStringWideCharToChar00);
 tolua_function(tolua_S,"SysLoadStringResource",tolua_lua_maapi_mosync_SysLoadStringResource00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_lua_maapi_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_lua_maapi);
 lua_pushstring(tolua_S, "lua_maapi");
 lua_call(tolua_S, 1, 0);
 return 1;
}
