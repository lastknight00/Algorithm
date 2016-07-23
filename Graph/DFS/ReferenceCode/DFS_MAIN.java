import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Vector;
 
class DFS_MAIN
{
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	int s = sc.nextInt();
    	DFS dfs = new DFS(n);
    	for(int i = 0; i < m; i++) {
    		dfs.addEdge(new Edge(sc.nextInt(), sc.nextInt(), 0));
    	}
    	List<Node> result = dfs.dfs(s);
    	for(int i = 0; i < result.size(); i++) {
    		System.out.print(result.get(i).getNo() + " ");
    	}
    }
}

class DFS {
	private int nodeCount;
	private Vector<Node>[] v;
	private Node[] nodeList;
	public DFS(int n) {
		this.nodeCount = n;
		v = new Vector[n + 1];
		nodeList = new Node[n + 1];
		for(int i = 1; i <= n; i++) {
			nodeList[i] = new Node(i);
			v[i] = new Vector<Node>();
		}
	}
	public void addEdge(Edge e){
		if(e.getFrom() < 1 || e.getTo() > nodeCount) return;
		v[e.getFrom()].add(nodeList[e.getTo()]);
	}
	public List<Node> dfs(int startIndex) {
		List<Node> retval = new ArrayList<Node>(nodeCount + 1);
		boolean[] visited = new boolean[nodeCount + 1];
		dfs(retval, visited, startIndex);
		
		return retval;
	}
	private void dfs(List<Node> retval, boolean[] visited, int cur){
		visited[cur] = true;
		retval.add(nodeList[cur]);
		for(int i = 0; i < v[cur].size(); i++) {
			if(visited[v[cur].get(i).getNo()]) {
				continue;
			} else {
				dfs(retval, visited, v[cur].get(i).getNo());
			}
		}
	}
}

class Node{
	private int no;
	public Node(int n){
		this.no = n;
	}
	public int getNo() {
		return no;
	}
	public void setNo(int no) {
		this.no = no;
	}
}

class Edge {
	private int from, to, weight;
	public Edge(int from, int to, int weight) {
		this.from = from;
		this.to = to;
		this. weight = weight;
	}
	public int getFrom() {
		return from;
	}
	public void setFrom(int from) {
		this.from = from;
	}
	public int getTo() {
		return to;
	}
	public void setTo(int to) {
		this.to = to;
	}
	public int getWeight() {
		return weight;
	}
	public void setWeight(int weight) {
		this.weight = weight;
	}
}