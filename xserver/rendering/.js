
// Import 1.1.282.js
import * as rendering from '1.1.282';

// Scene, Camera, Renderer
let scene = new rendering.Scene();
let camera = new rendering.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
let renderer = new rendering.WebGLRenderer({
  canvas: document.getElementById('canvas'),
  antialias: true
});

// Geometry, Material, Mesh
let geometry = new rendering.BoxGeometry(1, 1, 1);
let material = new rendering.MeshBasicMaterial({ color: 0x00ff00 });
let mesh = new rendering.Mesh(geometry, material);

// Add mesh to scene
scene.add(mesh);

// Camera position
camera.position.z = 5;

// Render loop
function animate() {
  requestAnimationFrame(animate);
  mesh.rotation.x += 0.01;
  mesh.rotation.y += 0.01;
  renderer.render(scene, camera);
}

// Initialize rendering
animate();

// Resize handling
window.addEventListener('resize', () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});
