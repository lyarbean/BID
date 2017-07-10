#ifndef DATAFRAMESQL_H_
#define DATAFRAMESQL_H_

class DataFrameSql : public DataFrameProvider 
{
public:
	DataFrameSql();
	virtual ~DataFrameSql(){}
	bool hasNext() override;
	
};
#endif // DATAFRAMESQL_H_
