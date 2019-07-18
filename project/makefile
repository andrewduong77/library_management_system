CXXFLAGS = -std=c++11
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: executable

executable: and7697_main.o and7697_View.o and7697_Controller.o and7697_Dialog.o and7697_Media.o and7697_Bundle.o and7697_Book.o and7697_Movie.o and7697_Video_Game.o and7697_Music_Album.o and7697_Television_Show_Season.o and7697_Library.o and7697_Transaction.o and7697_Date.o and7697_Librarian.o and7697_Customer.o
	$(CXX) $(CXXFLAGS) and7697_main.o and7697_View.o and7697_Controller.o and7697_Dialog.o and7697_Media.o and7697_Bundle.o and7697_Book.o and7697_Movie.o and7697_Video_Game.o and7697_Music_Album.o and7697_Television_Show_Season.o and7697_Library.o and7697_Transaction.o and7697_Date.o and7697_Librarian.o and7697_Customer.o $(GTKFLAGS)
	./a.out

and7697_main.o: and7697_main.cpp and7697_View.h and7697_Controller.h and7697_Dialog.h and7697_Media.h and7697_Bundle.h and7697_Book.h and7697_Movie.h and7697_Video_Game.h and7697_Music_Album.h and7697_Television_Show_Season.h and7697_Library.h and7697_Transaction.h and7697_Date.h and7697_Librarian.h and7697_Customer.h
	$(CXX) $(CXXFLAGS) -c and7697_main.cpp $(GTKFLAGS)

and7697_View.o: and7697_View.cpp and7697_View.h
	$(CXX) $(CXXFLAGS) -c and7697_View.cpp $(GTKFLAGS)

and7697_Controller.o: and7697_Controller.cpp and7697_Controller.h
	$(CXX) $(CXXFLAGS) -c and7697_Controller.cpp $(GTKFLAGS)

and7697_Dialog.o: and7697_Dialog.cpp and7697_Dialog.h
	$(CXX) $(CXXFLAGS) -c and7697_Dialog.cpp $(GTKFLAGS)

and7697_Media.o: and7697_Media.cpp and7697_Media.h
	$(CXX) $(CXXFLAGS) -c and7697_Media.cpp $(GTKFLAGS)

and7697_Bundle.o: and7697_Bundle.cpp and7697_Bundle.h
	$(CXX) $(CXXFLAGS) -c and7697_Bundle.cpp $(GTKFLAGS)

and7697_Book.o: and7697_Book.cpp and7697_Book.h
	$(CXX) $(CXXFLAGS) -c and7697_Book.cpp $(GTKFLAGS)

and7697_Movie.o: and7697_Movie.cpp and7697_Movie.h
	$(CXX) $(CXXFLAGS) -c and7697_Movie.cpp $(GTKFLAGS)

and7697_Video_Game.o: and7697_Video_Game.cpp and7697_Video_Game.h
	$(CXX) $(CXXFLAGS) -c and7697_Video_Game.cpp $(GTKFLAGS)

and7697_Music_Album.o: and7697_Music_Album.cpp and7697_Music_Album.h
	$(CXX) $(CXXFLAGS) -c and7697_Music_Album.cpp $(GTKFLAGS)

and7697_Television_Show_Season.o: and7697_Television_Show_Season.cpp and7697_Television_Show_Season.h
	$(CXX) $(CXXFLAGS) -c and7697_Television_Show_Season.cpp $(GTKFLAGS)

and7697_Library.o: and7697_Library.cpp and7697_Library.h
	$(CXX) $(CXXFLAGS) -c and7697_Library.cpp $(GTKFLAGS)

and7697_Transaction.o: and7697_Transaction.cpp and7697_Transaction.h
	$(CXX) $(CXXFLAGS) -c and7697_Transaction.cpp $(GTKFLAGS)

and7697_Date.o: and7697_Date.cpp and7697_Date.h
	$(CXX) $(CXXFLAGS) -c and7697_Date.cpp $(GTKFLAGS)

and7697_Librarian.o: and7697_Librarian.cpp and7697_Librarian.h
	$(CXX) $(CXXFLAGS) -c and7697_Librarian.cpp $(GTKFLAGS)

and7697_Customer.o: and7697_Customer.cpp and7697_Customer.h
	$(CXX) $(CXXFLAGS) -c and7697_Customer.cpp $(GTKFLAGS)

clean:
	rm -f *.o a.out

