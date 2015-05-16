#include "mainwindow.h"
#include <QApplication>

#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h" // for the driver
#include "mongo/bson/bson.h"

#include <memory> //auto_ptr

void run() {
  mongo::DBClientConnection c;

  std::string error;
  c.connect("ds031832.mongolab.com:31832");

  bool yes = c.auth("secondform_dream_list", "secondform", "gogosecondform1!", error, true);
  //c.connect("localhost");



  std::auto_ptr<mongo::DBClientCursor> cursor =
       //c.query("secondform_dream_list.secondform_dream_list", MONGO_QUERY());
          c.query("secondform_dream_list.secondform_dream_list", mongo::BSONObj());
          //c.query("secondform_dream_list", MONGO_QUERY(""));
   while (cursor->more()) {
       mongo::BSONObj p = cursor->next();
       std::cout << p.getStringField("ORGANIZATION") << std::endl;
   }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    mongo::client::initialize();
    try {
        run();
        std::cout << "connected ok" << std::endl;
    } catch( const mongo::DBException &e ) {
        std::cout << "caught " << e.what() << std::endl;
    }

    return a.exec();
}
