#include "dataframeprovider.h"
#include <fstream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

// TODO configurable
#define TARGET_HOST "localhost"
#define TARGET_USER "worlduser"
#define TARGET_PASS "worldpass"
#define TARGET_DB "world"

// sql::SQLException
class DataFrameProviderPrivate {
public:
	DataFrameProviderPrivate();
	~DataFrameProviderPrivate();
	void initialize();
	bool isInitialized();
	std::shared_ptr<sql::Statement> statement() { return m_sqlStatement; }
private:
	bool m_isInitialized = false;\
	std::shared_ptr<sql::Connection> m_sqlConnection;
	std::shared_ptr<sql::Statement> m_sqlStatement;
};

DataFrameProviderPrivate::DataFrameProviderPrivate() {

}

DataFrameProviderPrivate::~DataFrameProviderPrivate() {
	if (m_isInitialized) {

	}
}

void DataFrameProviderPrivate::initialize(const std::string&  host, const std::string& user, const std::string& pass, const std::string& database {
	sql::Driver* driver = get_driver_instance();
	m_sqlConnection.reset(driver->connect(url, user, pass));
	m_sqlConnection->setSchema(database);
	m_sqlStatement->reset (m_sqlConnection->createStatement());
}


DataFrameProvider::DataFrameProvider() : m_d(new DataFrameProviderPrivate) {}

void DataFrameProvider::load(const std::string& file)
{
	if (!m_d->isInitialized())
	{
		// throw ....
		m_d->initialize();
		return;
	}
	if (file.empty())
	{
		// throw ...
		return;
	}
#if USE_MMAP
	int fd = open(file.c_str(), O_RDONLY);
	if (fd == -1)
	{
		//throw
		return;
	}
	struct stat sb;
	if (fstat(fd, &sb) == -1)
	{
		// throw
		return;
	}
	size_t length;
	char* addr = mmap(nullptr, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (addr == MAP_FAILED)
	{
		// throw
		return;
	}
	
	munmap(addr, sb.st_size);
	close(fd);
#else
	std::ifstream filestream(file, std::ios::in);
	if (!filestream.is_open()) {
		//throw ...
		return;
	}
	std::string line;

	while (getline(filestream, line))
	{
		// TODO split line and convert to a DataFrame
		DataFrame df;
		fromString(line, df);
		append(df);
	}
#endif
}


std::vector<DataFrame> DataFrameProvider::execute(const std::string& query) {


}

void DataFrameProvider::append(const DataFrame& df) {
	m_d->statement->execute("....");
}
