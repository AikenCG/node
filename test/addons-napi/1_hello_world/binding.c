#include <node_api.h>
#include "../common.h"
#include <string.h>

napi_value Method(napi_env env, napi_callback_info info) {
  napi_value world;
  const char* str = "world";
  size_t str_len = strlen(str);
  NAPI_CALL(env, napi_create_string_utf8(env, str, str_len, &world));
  return world;
}

void Init(napi_env env, napi_value exports, napi_value module, void* priv) {
  napi_property_descriptor desc = DECLARE_NAPI_PROPERTY("hello", Method);
  NAPI_CALL_RETURN_VOID(env, napi_define_properties(env, exports, 1, &desc));
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
