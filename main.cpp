#include "dataframeprovider.h"
//#include "dataframesql.h"

int main()
{
	std::shared_ptr<DataFrameProvider> dfp(new DataFrameProvider);
	//dfp->setConfig(...);
	// load source
	try {
		dfp->load("/data/file.data");
	} catch (...) {
	}
	// to read out
	try {
		// Query q( ....);
		std::string  q;
		std::vector<DataFrame> dfs = dfp->execute(q);
	}
	catch (...)
	{

	}
	return 0;
}
