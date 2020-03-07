package object_oriented_design;

import java.util.Iterator;
import java.util.NoSuchElementException;

class Song {
	private String name;
	private String artist;
	private int year;
	private int rating;
	
	public Song(String name, String a, int y, int r) {
		this.name = name;
		this.artist = a;
		this.year = y;
		this.rating = r;
	}
	
	public void print() {
		
		System.out.println(name + " is by " + artist + " made in " + year + " rated by me a " + rating + ".");  
	}
}

public class IterableMusicPlayer implements Iterable<Song>{
	
	final static int CAPACITY = 100;
	private Song[] library;
	private int size;
	
	public IterableMusicPlayer() {
		library = new Song[CAPACITY];
		size = 0;
	}
	
	public int size() {
		return size;
	}
	
	public boolean addSong(Song s) {
		if (size == CAPACITY) {
			System.out.println("Library is full");
			return false;
		}
		library[size] = s;
		size++;
		return true;
	}
	
	public Iterator<Song> iterator() {
		return new SongIterator<Song>();
	}
	
	private class SongIterator<E> implements Iterator<E> {
		private int currentLocation;
		
		// Constructor
		SongIterator() { 
			currentLocation = 0;
		}
		
		@Override 
		public boolean hasNext() {
			return currentLocation < size();
		}
	
		@Override
		public E next() throws NoSuchElementException {
			if (hasNext()) {
				E ret_val = (E)library[currentLocation];
				currentLocation++; 
				return ret_val;
			}
			else 
				throw new NoSuchElementException();
		}
	
		@Override
		public void remove() {
			throw new UnsupportedOperationException();
			// this is bad because breaks substitutability. 
		}
	}
	public static void main(String[] args) {
		IterableMusicPlayer p = new IterableMusicPlayer();
		p.addSong(new Song("Hello", "Adele", 2015, 5));
		p.addSong(new Song("Baby", "Justin Bieber", 2009, 4));
		p.addSong(new Song("Imagine", "John Lennon", 1971, 5));
		
		for (Song s: p) {
			s.print();
		}
	}
}
