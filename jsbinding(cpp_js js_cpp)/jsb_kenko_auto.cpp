#include "jsb_kenko_auto.h"
#include "cocos2d_specifics.hpp"

std::string os_info() {
	CCLOG("it's c++ os_info here");
    return "os_info";
}

bool jsb_callback(JSContext *cx, uint32_t argc, JS::Value *vp) {
	CCLOG("it's c++ testCallback here");
    JSContext* jc = ScriptingCore::getInstance()->getGlobalContext();
    // ע�Ͳ����ʺ��ж��󻯵ĵ���
	// �ο���http://www.tairan.com/archives/4902
    //jsval v[2];
	//v[0] = int32_to_jsval(jc, 32);
    //v[1] = int32_to_jsval(jc, 12);
    
    // ͨ�� ScriptingCore ��װ�õķ���ʵ�ֻص������԰������ǽ�ʡ�ܶ�ϸ���ϵ��о�
	//js_proxy_t * p = jsb_get_native_proxy();
    //return ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(p->obj), "cpp_callback", 2, v);		//2�ǲ���������v�ǲ����б�
	
	//�ҵ�һ�����ʺ�ȫ�ֺ����ķ���
	jsval ret;
	return ScriptingCore::getInstance()->evalString("cpp_callback(2,3)", &ret);
}
 
bool jsb_os_info(JSContext *cx, uint32_t argc, JS::Value *vp) {
    jsval ret = std_string_to_jsval(cx, os_info());
    JS_SET_RVAL(cx, vp, ret);
 
    return true;
}
 
void register_jsb_kenko_all(JSContext *cx, JSObject *obj) {
    JS_DefineFunction(cx, obj, "osInfo", jsb_os_info, 0, 0);  
    JS_DefineFunction(cx, obj, "test_cpp_callback", jsb_callback, 0, 0);  
}