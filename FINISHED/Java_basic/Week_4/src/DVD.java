
public class DVD extends Item{
//	private String title;
	private String director;
//	private int playingTime;
//	private boolean gotIt = false;
//	private String comment;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	public void print() {
		// TODO Auto-generated method stub
		System.out.println("DVD "+getTitle()+":"+director);
	}

	public DVD(String title, String director, int playingTime, boolean gotIt,String comment) {
		super(title,playingTime,comment,gotIt);
//		this.title = title;
		this.director = director;
//		this.playingTime = playingTime;
//		this.comment = comment;
	}

}
