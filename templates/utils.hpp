namespace utils {
	template <typename T, typename... Args>
	void setValues(const T& value, T& first, Args&... args) {
    	first = value; 
		if constexpr (sizeof...(args) > 0) {setValues(value, args...);}
	}

	template <typename T>
	void setMax(T& target, const T& value) { if (value > target) {target = value;}}
	
	template <typename T>
	void setMin(T& target, const T& value) { if (value < target) {target = value;}}
}