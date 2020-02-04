#version 150

const int number_of_targets = 100;

uniform float time;
uniform vec2 resolution;
uniform vec2 targets[number_of_targets];

out vec4 outputColor;

void main() {

  vec2 p = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);
  float b = step(gl_FragCoord.x, resolution.y * 0.5);
  vec3 color = vec3(1.0 - b);
  
   for(int i = 0; i < number_of_targets; i++){

    vec2 t = vec2(targets[i].x, -targets[i].y) / min(resolution.x, resolution.y) * 2.0;
    t.xy += vec2(-resolution.x, resolution.y) / min(resolution.x, resolution.y);

	vec3 v = vec3(smoothstep(0.01, 1.0, 0.015 / length(p - t)));
	color += ((b == 0) ? -v : v);
  }

  outputColor = vec4(color, 1.0);
}