import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;
 
class Main
{
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	int m = sc.nextInt();
    	int s = sc.nextInt();
    	Graph g = new Graph(n);
    	for(int i = 0; i < m; i++) {
    		int x = sc.nextInt();
    		int y = sc.nextInt();
    		g.addEdge(new Edge(x, y, 0));
    		g.addEdge(new Edge(y, x, 0));
    	}
    	g.sort(new Comparator<Node>() {
			public int compare(Node o1, Node o2) {
				return o1.getNo() - o2.getNo();
			}
    	});
    	List<Node> result = g.dfs(s);
    	for(int i = 0; i < result.size(); i++) {
    		System.out.print(result.get(i).getNo() + " ");
    	}
    	System.out.println();
    	result = g.bfs(s);
    	for(int i = 0; i < result.size(); i++) {
    		System.out.print(result.get(i).getNo() + " ");
    	}
    }
}

class Graph {
	private int nodeCount;
	private Vector<Node>[] edgeList;
	private Node[] nodeList;
	public Graph(int n) {
		this.nodeCount = n;
		edgeList = new Vector[n + 1];
		nodeList = new Node[n + 1];
		for(int i = 1; i <= n; i++) {
			nodeList[i] = new Node(i);
			edgeList[i] = new Vector<Node>();
		}
	}
	public void addEdge(Edge e){
		if(e.getFrom() < 1 || e.getTo() > nodeCount) return;
		edgeList[e.getFrom()].add(nodeList[e.getTo()]);
	}
	public void sort(Comparator<Node> comp) {
		for(int i = 1; i <= nodeCount; i++) {
			Collections.sort(edgeList[i], comp);
		}
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
		for(int i = 0; i < edgeList[cur].size(); i++) {
			if(visited[edgeList[cur].get(i).getNo()]) {
				continue;
			} else {
				dfs(retval, visited, edgeList[cur].get(i).getNo());
			}
		}
	}
	public List<Node> bfs(int startIndex) {
		List<Node> retval = new ArrayList<Node>(nodeCount + 1);
		boolean[] visited = new boolean[nodeCount + 1];
		Queue<Node> q = new LinkedList<Node>();
		q.add(nodeList[startIndex]);
		visited[startIndex] = true;
		while(!q.isEmpty()) {
			Node cur = q.poll();
			retval.add(cur);
			for(int i = 0; i < edgeList[cur.getNo()].size(); i++) {
				if(!visited[edgeList[cur.getNo()].get(i).getNo()]){
					q.add(edgeList[cur.getNo()].get(i));
					visited[edgeList[cur.getNo()].get(i).getNo()] = true;
				}
			}
		}
		return retval;
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