
public class CD extends Item{
//	private String title;
	private String artist;
	private int numofTracks;
//	private int playingTime;
//	private boolean gotIt = false;
//	private String comment;
	
	public CD(String title, String artist, int numofTracks, int playingTime, boolean gotIt,String comment) {
		super(title,playingTime,comment,gotIt);
//		this.title = title;
		this.artist = artist;
		this.numofTracks = numofTracks;
//		this.playingTime = playingTime;
//		this.comment = comment;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	public void print() {
		System.out.println("CD "+ getTitle()+":"+artist);
	}

}
