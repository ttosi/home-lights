const routes = [
  {
    path: '/',
    component: () => import('layouts/layout.vue'),
    children: [
      { path: '', component: () => import('pages/Index.vue') },
      { path: 'livingroom', component: () => import('pages/LivingRoom.vue') },
      { path: 'bedroom', component: () => import('pages/Bedroom.vue') },
      { path: 'kitchen', component: () => import('pages/Kitchen.vue') },
      { path: 'presets', component: () => import('pages/Presets.vue') },
      { path: 'settings', component: () => import('pages/Settings.vue') },
    ]
  }
]

// Always leave this as last one
if (process.env.MODE !== 'ssr') {
  routes.push({
    path: '*',
    component: () => import('pages/Error404.vue')
  })
}

export default routes
