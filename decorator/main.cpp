#include <iostream>
#include <string>

class DataSource {
public:
    virtual ~DataSource() {}
    virtual void writeData(const std::string& data) = 0;
    virtual std::string readData() = 0;
};

class FileDataSource : public DataSource {
public:
    FileDataSource(const std::string& filename) : filename_(filename) {}

    void writeData(const std::string& data) override {
        std::cout << "Escrevendo dados no arquivo " << filename_ << std::endl;
    }

    std::string readData() override {
        return "Dados lidos do arquivo " + filename_;
    }

private:
    std::string filename_;
};

class DataSourceDecorator : public DataSource {
protected:
    DataSource* wrappee_;

public:
    DataSourceDecorator(DataSource* source) : wrappee_(source) {}

    void writeData(const std::string& data) override {
        wrappee_->writeData(data);
    }

    std::string readData() override {
        return wrappee_->readData();
    }
};

class EncryptionDecorator : public DataSourceDecorator {
public:
    EncryptionDecorator(DataSource* source) : DataSourceDecorator(source) {}

    void writeData(const std::string& data) override {
        std::cout << "Encriptando os dados" << std::endl;
        wrappee_->writeData("Dados encriptados: " + data);
    }

    std::string readData() override {
        std::string encryptedData = wrappee_->readData();
        std::cout << "Decifrando os dados" << std::endl;
        return "Dados decifrados: " + encryptedData;
    }
};

class CompressionDecorator : public DataSourceDecorator {
public:
    CompressionDecorator(DataSource* source) : DataSourceDecorator(source) {}

    void writeData(const std::string& data) override {
        std::cout << "Comprimindo os dados" << std::endl;
        wrappee_->writeData("Dados comprimidos: " + data);
    }

    std::string readData() override {
        std::string compressedData = wrappee_->readData();
        std::cout << "Descomprimindo os dados" << std::endl;
        return "Dados descomprimidos: " + compressedData;
    }
};

int main() {
    DataSource* source = new FileDataSource("somefile.dat");
    source->writeData("salaryRecords");

    source = new CompressionDecorator(source);
    source->writeData("salaryRecords");

    source = new EncryptionDecorator(source);
    source->writeData("salaryRecords");

    delete source;
    return 0;
}
