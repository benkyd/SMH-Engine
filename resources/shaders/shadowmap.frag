#version 330

out float fragdepth;

void main(){
    gl_FragDepth = gl_FragCoord.z;
}
