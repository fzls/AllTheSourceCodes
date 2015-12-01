
public class MP3 extends Item{
//	增加了专辑名称，版权信息，比特率，评级信息，不需要修改Item的代码
	private String album;
	private String copyright;
	private int bitRate;
	private int rate;
	
	public MP3(String title, int playingTime, String comment, boolean gotIt, String album, String copyright,
			int bitRate, int rate) {
		super(title, playingTime, comment, gotIt);
		this.album = album;
		this.copyright = copyright;
		this.bitRate = bitRate;
		this.rate = rate;
	}
	public void print(){
		System.out.println("MP3 :"+getTitle()+" from "+album);
	}
//	getTitle()函数式item中的一个函数，用于返回私有变量title
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
	}

}
