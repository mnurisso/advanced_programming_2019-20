/* *********************************************************
 * It's a way to wrap a standard type and count the number of 
 * operations done during the evauation
 * ********************************************************* */
template <typename T>
struct Measure{
	T value;
	measure(){++default_ctor;}
	/* You have to define override of ==, != etc...*/
	bool operator==(const T& a, const T& b){
		++eq_counter;
		return a.value==b.value;
	}
}
/* *****************************************************
 * You can construct an array of different counters for 
 * different type of operations that can be done 
 *
 * The size of the Measure<double> will be the same of 
 * double itself, making the code slower, but not incre-
 * dibly.
 * 
 * To define this custom double:
 * sort<Measure<double>>
 * ***************************************************** */
