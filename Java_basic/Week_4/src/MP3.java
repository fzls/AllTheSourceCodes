
public class MP3 extends Item{
//	������ר�����ƣ���Ȩ��Ϣ�������ʣ�������Ϣ������Ҫ�޸�Item�Ĵ���
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
//	getTitle()����ʽitem�е�һ�����������ڷ���˽�б���title
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
	}

}
