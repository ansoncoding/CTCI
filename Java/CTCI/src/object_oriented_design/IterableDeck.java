package object_oriented_design;

import java.util.Iterator;
import java.util.ArrayList;

enum CardSuit {
	CLUBS(0),
	SPADES(1),
	HEARTS(2),
	DIAMOND(3);
	private int value;
	private CardSuit(int value) {
		this.value = value;
	}
}

enum CardValue {

	 ACE(1),
	 TWO(2),
	 THREE(3),
	 FOUR(4),
	 FIVE(5),
	 SIX(6), 
	 SEVEN(7),
	 EIGHT(8),
	 NINE(9),
	 TEN(10),
	 JACK(11),
	 QUEEN(12),
	 KING(13),
	 JOKER(0);
	 private int value;
	 private CardValue(int value) {
	     this.value = value;
	}
}

class Card {
	CardValue v;
	CardSuit s;
	public Card(CardSuit s, CardValue v) {
		this.v = v;
		this.s = s;
	}
	public void print() {
		System.out.println(v + " of " + s);
	}
}

public class IterableDeck implements Iterable<Card> {
	
	private ArrayList<Card> deck;
	public IterableDeck() {
		deck = new ArrayList<Card>();
		for (CardSuit s : CardSuit.values()) {
			for (CardValue v : CardValue.values()) {
				deck.add(new Card(s, v));
			}
		}
	}
	
	// Iterator using the ArrayList iterator from Java Collections
	public Iterator iterator() {
		return deck.iterator();
	}

	public static void main(String[] args) {
		IterableDeck d = new IterableDeck();
		for (Card c : d) {
			c.print();
		}
	}

}
