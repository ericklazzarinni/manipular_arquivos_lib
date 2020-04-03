#ifndef MANIPULARARQUIVOS_H
#define MANIPULARARQUIVOS_H
 
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
 
class ManipularArquivos
{
public:
   ManipularArquivos(int pin_cs);
   boolean testar();
   boolean criarArquivo(String nomeArquivo);
   boolean removerArquivo(String nomeArquivo);
   boolean criarDiretorio(String caminho_diretorio);
   boolean removerDiretorio(String caminho_diretorio); 
   void listarPastas(File dir,  int numTabs);
   void fecharArquivo();
   boolean escrever(File arquivoBase, String nomeArquivo, String texto);
   void abrirLer(File arquivoBase, String nomeArquivo);

private:
   int pin_cs;
  
   
};
 
#endif