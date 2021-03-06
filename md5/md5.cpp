/*
 * compile this with:
 * 1. qmake -project -spec macx-g++
 * 2. qmake
 * 3. make
 *
 * clean:
 * make distclean
 */

#include <QDebug>
#include <QFile>
#include <QCryptographicHash>

int main(int argc, char* argv[]){
  QFile file;
  if (argc == 2)
    file.setFileName(argv[1]);
  else
    file.setFileName("./md5.cpp");
  
  if (file.open(QIODevice::ReadOnly))
  {
      QByteArray fileData = file.readAll();
  
      QByteArray hashData = QCryptographicHash::hash(fileData,QCryptographicHash::Md5); // or QCryptographicHash::Sha1
      qDebug() << hashData.toHex();  // 0e0c2180dfd784dd84423b00af86e2fc
  
  }
  return 0;
}
