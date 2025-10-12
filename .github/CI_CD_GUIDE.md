# CI/CD Configuration

## Workflows

### C Projects (`c-projects.yml`)
Builds all C projects using matrix strategy. Triggers on changes to `C/**`.

**Projects tested:** ls, printf, my_hunter, my_navy, my_radar, sokoban

**Dependencies:** gcc, make, libncurses-dev, libcsfml-dev (for graphical projects)

### Python Projects (`python-projects.yml`)
Validates Python scripts across multiple versions (3.9, 3.10, 3.11). Triggers on changes to `Python/**`.

**Checks:** syntax validation, pylint, execution tests

## Adding New Projects

**C project:**
```yaml
# Edit .github/workflows/c-projects.yml
matrix:
  project: [ls, printf, my_navy, sokoban, my_radar, my_hunter, new_project]
```

**Python version:**
```yaml
# Edit .github/workflows/python-projects.yml
matrix:
  python-version: ['3.9', '3.10', '3.11', '3.12']
```

## Status Badges

Badges in main README show real-time build status. Check [Actions tab](../../actions) for detailed logs.
