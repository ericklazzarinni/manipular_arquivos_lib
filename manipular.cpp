#include "manipular.h"

int pin_cs;
//File arquivo; 
ManipularArquivos::ManipularArquivos(int pin_cs)
{
 this -> pin_cs = pin_cs; 
}
 
boolean ManipularArquivos::testar()
{
   if(SD.begin(pin_cs))
     return true;
   else
     return false;
     
}

boolean ManipularArquivos::criarArquivo(String nomeArquivo)
{
   File arquivo = SD.open(nomeArquivo, FILE_WRITE);
   if(arquivo){
     arquivo.close();
     return true;
    }
   else{
arquivo.close();
     return false;
}
     
}

void ManipularArquivos::fecharArquivo()
{
   // arquivo.close();  
}

boolean ManipularArquivos::criarDiretorio(String caminho_diretorio)
{
   
   return SD.mkdir(caminho_diretorio);
     
}

boolean ManipularArquivos::removerDiretorio(String caminho_diretorio)
{
   
   return SD.rmdir(caminho_diretorio);
     
}

boolean ManipularArquivos::escrever(File arquivoBase, String nomeArquivo, String texto)
{
   arquivoBase = SD.open(nomeArquivo, FILE_WRITE);
   if(arquivoBase)
{
    arquivoBase.println(texto);
    arquivoBase.close();
    return true;
}
   else
    {
    arquivoBase.close();
    return false;
  
}
     
}

boolean ManipularArquivos::removerArquivo(String nomeArquivo)
{
   
       return SD.remove(nomeArquivo);
     
}

void ManipularArquivos::abrirLer(File arquivoBase, String nomeArquivo)
{
   
  arquivoBase = SD.open(nomeArquivo);
  if (arquivoBase) {
    Serial.print("Conteudo de ");
    Serial.println(nomeArquivo);
    // Le todo o arquivo...
    while (arquivoBase.available()) {
      Serial.write(arquivoBase.read());
    }
    //Finalizado, fecha-se o arquivo
    arquivoBase.close();
  }
  else {
    // Se deu erro acima, aqui tambem dara.
     arquivoBase.close();
    Serial.println("Nao pude abrir o arquivo.");
  }
}

     


void ManipularArquivos::listarPastas(File dir,  int numTabs)
{
 while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      listarPastas(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }

}

