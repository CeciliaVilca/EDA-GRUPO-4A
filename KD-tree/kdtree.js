k = 2;
class Node{
	constructor(point, axis){
		this.point = point;
		this.left = null;
		this.right = null;
		this.axis = axis;
	}
}


function build_kdtree(points, depth = 0){
	var n = points.length;
	var axis = depth % k;

	if ( n<=0){
		return null;
	}
	if(n==1){
		return new Node(points[0],axis)
	}
	var median = Math.floor(points.length/2);

	points.sort(function(a,b){
		return a[axis] - b[axis];
	});

	var left = points.slice(0,median);
	var right = points.slice(median+1);

	var node = new Node(points[median].slice(0,k),axis);
	node.left = build_kdtree(left,depth +1);
	node.right = build_kdtree(right,depth +1);

	return node;
	
}
function getHeight(node) 
{
	if(!node) return 0;
	return Math.max(1 + getHeight(node.left), 1 + getHeight(node.right));
}

function generate_dot(node)
{
	if(!node) return;
	var left = node.left;
	var right = node.right;
	if(left)
	{
		console.log('"'+node.point +'"'+ "->" + '"'+left.point+'"');
		generate_dot(left);
	} 
	if(right)
	{
		console.log('"' + node.point +'"'+ "->" +'"'+ right.point+'"');
		generate_dot(right);	
	}
}

function distanceSquared(point1,point2)
{
	var distance = 0;
	for (var i = 0; i < k; i++) 
	{
		distance += Math.pow((point1[i] - point2[i]),2);
	}
	return Math.sqrt(distance);
}

function closest_point_brute_force(points,point)
{
	var distance = Number.MAX_VALUE;
	var point_c = null;
	for (var i = 0; i < points.length; i++) 
	{
		var auxiliar = distanceSquared(points[i],point);
		//console.log(points[i] + "---->" +auxiliar);
		if(auxiliar < distance)
		{
			distance = auxiliar;
			point_c = points[i];
		}
	}
	return distance;
}

function naive_closest_point(node,point, depth=0, best = null)
{
	if (!node) return best; 
	best = min(distanceSquared(node.point,point));
	if (node.point[node.axis] > point[node.axis])
	{
		if(node.left) best = min(best, naive_closest_point(node.left,point,depth++,best));
	} 
	else
	{
		if(node.right) best = min(best,naive_closest_point(node.right,point,depth++,best));
	}
	return best;
}


function closer_point(point,p1,p2)
{
	
	if(!p1) return p2;
	if(!p2) return p1;
	if(p1.estado==false && p2.estado==false) return null;
	if(p1.estado == false) return p2;
	if (p2.estado == false) return p1;

	if(distanceSquared(point,p1.point) > distanceSquared(point,p2.point)) return p2;
	return p1;

}

function closest_point(node,point_2,depth = 0)
{

	if (node == null) return ; 
	//best = min(distanceSquared(node.point,point));
	var nb = null;
	var ob = null;
	if (node.point[node.axis] > point_2[node.axis])
	{
		//if(node.left) best = min(best, naive_closest_point(node.left,point,depth++,best));
		nb = node.left;
		ob = node.right;
	} 
	else
	{
		//if(node.right) best = min(best,naive_closest_point(node.right,point,depth++,best));
		nb = node.right;
		ob = node.left;
	}
	
	var best = closer_point(point_2,closer_point(point_2,closest_point(nb,point_2,depth+1),node),best);
	
	if (distanceSquared(best.point,point_2) > Math.abs(point_2[node.axis] - node.point[node.axis]))
	{
		best2 = closer_point(point_2,closest_point(ob,point_2,depth+1),node);
		
	}
	best = closer_point(point_2,best2,best);
	
	
	//if(best.estado == false) return;
	return best;	
}

function closest_n_points(node,point_2,cant_puntos)
{
	var closest_points =  [];
	for (var i = cant_puntos - 1; i >= 0; i--) 
	{
		punto = closest_point(node,point_2);
		if(punto == null) continue;
		punto.estado = false;
		closest_points.push(punto);
	}
	var ans = []
	for (var i = closest_points.length - 1; i >= 0; i--) 
	{
		punto = closest_points[i];
		punto.estado = true;
		ans.push(punto.point);
	}
	return ans;
}



function range_query_circle ( node , center , radio , queue , depth = 0 ){
	if (node==null) return null;

	var axis = node.axis ;
	var nb = null;
	var ob = null;

	if (center[axis] < node.point[axis]){
		nb=node.left;
		ob=node.right;
	} else {
		nb=node.right;
		ob=node.left;
	}

	var best=closer_point(center,node,range_query_circle(nb,center,radio,queue,depth+1));

	if(Math.abs(center[axis]-node.point[axis]) <= radio || distanceSquared(center,best.point) > Math.abs(center[axis]-node.point[axis])){

		if(distanceSquared(center,node.point) <= radio){

			queue.push(node.point);
		}

		best=closer_point(center,best,range_query_circle(ob,center,radio,queue,depth+1));
	}

	return best ;
}

function range_query_rect ( node , center , hug , queue , depth = 0 ){
	if (node==null) return null;

	var axis = node.axis ;
	var nb = null;
	var ob = null;
	
	if (center[axis]<node.point[axis]){
		nb=node.left;
		ob=node.right;
	} else {
		nb=node.right;
		ob=node.left;
	}
	var best=closer_point(center,node,range_query_rect(nb,center,hug,queue,depth+1));

	if(Math.abs(center[axis]-node.point[axis])<=hug[axis]*2 || distanceSquared(center,best.point)>Math.abs(center[axis]-node.point[axis])){

		if(Math.abs(center[0]-node.point[0])<=hug[0] && Math.abs(center[1]-node.point[1])<=hug[1]){

			queue.push(node.point);
		}
		best=closer_point(center,best,range_query_rect(ob,center,hug,queue,depth+1));
	}

	return best ;
}

