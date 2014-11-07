#ifdef __WIN32
	#define IF_WIN(w,l) w
#else
	#define IF_WIN(w,l) l
#endif

#define debug_file(foo) std::freopen(foo,"w",stdout);
#define snafu __FILE__,__LINE__,__func__
#define debug(...) __debug(__VA_ARGS__);
void __debug(const char* file,const int line,const char* function,const char* alt = "");
template <class T> T assert(T foo,const char* file,const int line,const char* function,const char* alt = ""){
	if((foo)) return foo;
	__debug(file,line,function,alt);
	std::exit(0);
}

#define safe(TemplateType,Type) static_assert(std::is_same<TemplateType,Type>::value&&!std::is_rvalue_reference<TemplateType>::value,"Type "#Type" expected as a non-rvalue reference parameter.");
