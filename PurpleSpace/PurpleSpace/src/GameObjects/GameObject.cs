using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using PurpleSpace.src.animation;
using System.Collections;
using Microsoft.Xna.Framework;
using PurpleSpace.src.Particles;

namespace PurpleSpace.src.GameObjects
{
    abstract class GameObject
    {
        protected List<Texture2D> textures;
        protected List<Animation> animations;
        public Vector2 position;
        protected Vector2 currentTextureSize;   //For get Borders
        protected List<WaterParticlesController> particleControllers; 
        /*
        public GameObject(Texture2D texture)
        {
            textures = new List<Texture2D>();
            animations = new List<Animation>();

            position = new Vector2(0,0);
            this.textures[0] = texture;
        }*/

        public GameObject() {
            textures = new List<Texture2D>();
            animations = new List<Animation>();
            position = new Vector2(0, 0);
            particleControllers = new List<WaterParticlesController>();
        }

        public void AddAnimation(Animation animation)
        {
            animations.Add(animation);
        }

        public void AddTexture(Texture2D texture)
        {
            textures.Add(texture);
        }

        public void AddParticleController(WaterParticlesController particleController)
        {
            particleControllers.Add(particleController);
        }

        public abstract void Update();

        public abstract void Draw(SpriteBatch spriteBatch);
    }
}
