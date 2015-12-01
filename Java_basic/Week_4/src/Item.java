
public class Item {
	private	String title;
	private int playingTime;
	private boolean gotIt = false;
	private String comment;
	public Item(String title,int playingTime, String comment,boolean gotIt) {
		super();
		this.title = title;
		this.playingTime=playingTime;
		this.comment=comment;
		this.gotIt=gotIt;
	}
	protected String getTitle(){
		return title;
	}
	public static void main(String[] args) {

	}

	public void print() {
		System.out.println("item");
	}

}
