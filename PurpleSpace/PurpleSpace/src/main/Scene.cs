using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PurpleSpace.src.GameObjects;
using Microsoft.Xna.Framework.Graphics;

namespace PurpleSpace.src.main
{
    class Scene
    {
        private List<GameObject> gameObjects;
        public Scene()
        {
            gameObjects = new List<GameObject>();
        }

        public void Update()
        {
            foreach (var gameObject in gameObjects)
            {
                gameObject.Update();
            }
        }

        public void Draw(SpriteBatch spriteBatch)
        {
            foreach (var gameObject in gameObjects)
            {
                gameObject.Draw(spriteBatch);
            }
        }

        public void AddGameObject(GameObject gameObject)
        {
            gameObjects.Add(gameObject);
        }

        public void RemoveGameObject(GameObject gameObject)
        {
            gameObjects.Remove(gameObject);
        }
    }
}
