export default {
  widgets: [
    { name: 'structure-menu' },
    {
      name: 'project-info',
      options: {
        __experimental_before: [
          {
            name: 'netlify',
            options: {
              description:
                'NOTE: Because these sites are static builds, they need to be re-deployed to see the changes when documents are published.',
              sites: [
                {
                  buildHookId: '5f400ff06acb21d825269f45',
                  title: 'Sanity Studio',
                  name: 'sanity-gatsby-blog-studio-4n9kvx12',
                  apiId: '5b4283c3-9b15-4911-8807-eb489e211d85'
                },
                {
                  buildHookId: '5f400ff73848e7ad047ff3f4',
                  title: 'Blog Website',
                  name: 'sanity-gatsby-blog-web-tbazkvwj',
                  apiId: '72a55ca5-dc25-41ce-97be-290efb1dd83b'
                }
              ]
            }
          }
        ],
        data: [
          {
            title: 'GitHub repo',
            value: 'https://github.com/gerhardmelseth/sanity-gatsby-blog',
            category: 'Code'
          },
          { title: 'Frontend', value: 'https://sanity-gatsby-blog-web-tbazkvwj.netlify.app', category: 'apps' }
        ]
      }
    },
    { name: 'project-users', layout: { height: 'auto' } },
    {
      name: 'document-list',
      options: { title: 'Recent blog posts', order: '_createdAt desc', types: ['post'] },
      layout: { width: 'medium' }
    }
  ]
}
