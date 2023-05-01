#include <sqlite3.h>
#include <stdio.h>

/*Não consegui testar no meu, pois não encontrei o arquivo CmakeLists.txt para conseguir incluir a bibloteca.
 * Tbm não consegui gerar o executável 😞*/

//Esta função é chamada para verificar a passagem de dados em um insert, por exemplo.
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for (i = 0; i<argc ; i++){
        printf("%s = %s\\n\", azColName[i], argv[i] ? argv[i] : \"NULL");
    }
    printf("\n");
    return 0;
}


int main(int argc, char* argv[]){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char* data = "Funcao CallBack chamada";
    char *createtables, *insert, *select;

    //Abre o banco de dados
    rc = sqlite3_open("ClinicaInfo.db",db);

    if(rc){
        fprintf(stderr,"Nao e possivel abrir o banco de dados: %s\n", sqlite3_errmsg(db));
        return(0);
    }else{
        fprintf(stdout, "O banco foi aberto com sucesso\n");
    }

    //criando as tabelas
    createtables = "CREATE TABLE IF NOT EXISTS Medico("
                   "CRM INT PRIMARY KEY NOT NULL,"
                   "Nome VARCHAR(100) NOT NULL,"
                   "Telefone VARCHAR(20),"
                   "Endereco VARCHAR(100),"
                   "Senha VARCHAR(8)"
                   ");"
                   "CREATE TABLE IF NOT EXISTS Paciente("
                   "CPF INT PRIMARY KEY,"
                   "Nome VARCHAR(100),"
                   "Telefone VARCHAR(20),"
                   "Endereco VARCHAR(200),"
                   "Sexo CHAR(1),"
                   "Data_Nascimento DATE"
                   ");"
                   "CREATE TABLE IF NOT EXISTS Relatorio("
                   "ID_relatorio INTEGER PRIMARY KEY,"
                   "CPF_paciente INT,"
                   "Data_relatorio DATE,"
                   "Causa VARCHAR(200),"
                   "Sintomas VARCHAR(200),"
                   "Medicamentos VARCHAR(200),"
                   "FOREIGN KEY (CPF_paciente) REFERENCES Paciente(CPF)"
                   ");";
    // comando select
    select = "SELECT * FROM Medico WHERE Nome = 'Dr. Pedro'";

    //comando insert
    insert =  "INSERT INTO Paciente (CPF, Nome, Telefone, Endereco, Sexo, Data_Nascimento)  "\
               "VALUES (123456789, 'João Silva', '987654321', 'Rua A, 123', 'M', '2000-01-01');"\
               "INSERT INTO Medico (CRM, Nome, Telefone, Endereco, Senha) "\
               "VALUES (1234, 'Dr. Pedro', '987654321', 'Avenida X, 789', 'senha123');";


    //inserindo os valores para teste
    rc = sqlite3_exec(db,insert, callback,0, &zErrMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr,"ERRO SQL: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"Dados inseridos com sucesso");
    }
}
    // executa o comando createtable
    rc = sqlite3_exec(db,createtables,callback, 0, &zErrMsg);

    if(rc != SQLITE_OK){
        fprintf(stderr,"ERRO SQL: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"Tabela Criada com Sucesso\n");
    }


    //executa o comando select para teste
    rc = sqlite3_exec(db,select,callback,(void*)data, &zErrMsg);

    if (rc != SQLITE_OK){
        fprintf(stderr,"SQL ERROR: %s", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout,"SELECT Efetuado com sucesso");


    sqlite3_close(db);

    return 0;
}