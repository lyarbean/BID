#ifndef DATAFRAMEPROVIDER_H_
#define DATAFRAMEPROVIDER_H_
#include <memory>
#include <vector>
// TODO Namespace
struct DataFrame {
	std::string id;
	std::string date;
};

// TODO exception
class DataFrameProviderPrivate;
class DataFrameProvider {
public:
	DataFrameProvider();
	virtual ~DataFrameProvider() {}
	// explicitly load data from \a from and save them back to underlying source, this is a blocking operation
	void load(const std::string& file);
	// read
	std::vector<DataFrame> execute(const std::string& query);
private:
	// write
	void append(const DataFrame&);
private:
	std::shared_ptr<DataFrameProviderPrivate> m_d;
};
#endif // DATAFRAMEPROVIDER_H_
